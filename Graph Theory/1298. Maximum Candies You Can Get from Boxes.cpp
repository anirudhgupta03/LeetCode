class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int n = keys.size();
        
        vector<int> vis(n, 0);
        queue<int> q;
        
        for(int i = 0; i < initialBoxes.size(); i++){
            q.push(initialBoxes[i]);
        }
        
        int sum = 0;
        
        while(!q.empty()){
            int sz = q.size();
            bool flag = false;
            while(sz--){
                int currBox = q.front();
                q.pop();

                if(vis[currBox]) continue;

                if(status[currBox] == 0){
                    if(q.size() == 0) break;
                    q.push(currBox);
                    continue;
                }
                
                flag = true;
                vis[currBox] = 1;

                for(int i = 0; i < keys[currBox].size(); i++){
                    status[keys[currBox][i]] = 1;
                }
                sum += candies[currBox];

                for(int i = 0; i < containedBoxes[currBox].size(); i++){
                    if(vis[containedBoxes[currBox][i]] == 0){
                        q.push(containedBoxes[currBox][i]);
                    }
                }
            }
            if(!flag){
                break;
            }
        }
        return sum;
    }
};
