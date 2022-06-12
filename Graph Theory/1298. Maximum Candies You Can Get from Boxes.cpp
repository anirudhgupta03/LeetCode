//Method - 1
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

//Method - 2
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int n = status.size();
        
        int ans = 0;
        
        vector<int> boxVis(n, 0), boxFound(n, 0);
        queue<int> q;
        
        for(int i = 0; i < initialBoxes.size(); i++){
            q.push(initialBoxes[i]);
        }
        
        while(!q.empty()){
            
            int box = q.front();
            boxFound[box] = 1;
            q.pop();
            
            if(boxVis[box] || status[box] == 0) continue;
            
            boxVis[box] = 1;
            ans += candies[box];
            
            for(int i = 0; i < containedBoxes[box].size(); i++){
                int insideBox = containedBoxes[box][i];
                if(boxVis[insideBox] == 0){
                    q.push(insideBox);
                }
            }
            
            for(int i = 0; i < keys[box].size(); i++){
                int boxKey = keys[box][i];
                if(boxFound[boxKey] && boxVis[boxKey] == 0){
                    q.push(boxKey);
                }
                status[boxKey] = 1;
            }
        }
        return ans;
    }
};
