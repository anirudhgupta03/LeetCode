//Ref: https://www.youtube.com/watch?v=vtxETRvR9JY
class Solution {
public:
    vector<string> findNextStates(string &curr){
        
        vector<string> res;
        
        for(int i = 0; i < 4; i++){
            char c = curr[i];
            if(c == '9'){
                curr[i] = '0';
                res.push_back(curr);
                curr[i] = '8';
                res.push_back(curr);
            }
            else if(c == '0'){
                curr[i] = '1';
                res.push_back(curr);
                curr[i] = '9';
                res.push_back(curr);
            }
            else{
                curr[i] = (char)(c + 1);
                res.push_back(curr);
                curr[i] = (char)(c - 1);
                res.push_back(curr);
            }
            curr[i] = c;
        }
        return res;
    }
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> vis;
        
        if(target.size() == 0){
            return -1;
        }
        
        for(int i = 0; i < deadends.size(); i++){
            vis.insert(deadends[i]);
        }
        
        queue<string> q;
        q.push("0000");
        int level = 0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curr = q.front();
                q.pop();
                
                if(vis.find(curr) != vis.end()) continue;
                vis.insert(curr);
                if(curr == target) return level;
                
                vector<string> v = findNextStates(curr);
                
                for(int i = 0; i < v.size(); i++){
                    if(vis.find(v[i]) == vis.end()){
                        q.push(v[i]);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
