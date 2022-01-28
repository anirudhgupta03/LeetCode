class Solution {
public:
    #define pis pair<int,string>
    char dx[4] = {'A','T','G','C'};
    vector<string> findNextStates(string &curr){
        
        vector<string> v;
        for(int i = 0; i < curr.size(); i++){
            char temp = curr[i];
            for(int j = 0; j < 4; j++){
                if(temp == dx[j]) continue;
                curr[i] = dx[j];
                v.push_back(curr);
            }
            curr[i] = temp;
        }
        return v;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_set<string> valid;
        
        for(auto &x: bank) valid.insert(x);
        queue<string> q;
        int level = 0;
        
        unordered_set<string> vis;
        q.push(start);
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                string curr = q.front();
                q.pop();
                
                if(curr == end){
                    return level;
                }
                if(vis.find(curr) != vis.end()) continue;
                vis.insert(curr);
                
                vector<string> v = findNextStates(curr);
                
                for(int i = 0; i < v.size(); i++){
                    if(vis.find(v[i]) == vis.end() && valid.find(v[i]) != valid.end()){
                        q.push(v[i]);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
