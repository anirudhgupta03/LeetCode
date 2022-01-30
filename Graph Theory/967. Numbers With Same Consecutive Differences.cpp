class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        string s;
        
        queue<string> q;
        
        for(int i = 1; i <= 9; i++){
            q.push(to_string(i));
        }
        
        vector<int> res;
        
        unordered_set<string> vis;
        
        while(!q.empty()){
            n--;
            int sz = q.size();
            while(sz--){
                string curr = q.front();
                q.pop();
                
                if(vis.find(curr) != vis.end()) continue;
                vis.insert(curr);
                
                if(n == 0){
                    res.push_back(stoi(curr));
                }
                int last = curr[curr.size() - 1] - '0';
                
                if(last + k <= 9){
                    curr.push_back(last + k + '0');
                    q.push(curr);
                    curr.pop_back();
                }
                if(last - k <= 9 && last - k >= 0){
                    curr.push_back(last - k + '0');
                    q.push(curr);
                    curr.pop_back();
                }
            }
            if(n == 0){
                break;
            }
        }
        return res;
    }
};
