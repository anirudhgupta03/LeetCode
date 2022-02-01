//Ref: https://www.youtube.com/watch?v=r_GCX5jalWM
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        
        int n = nums.size();
        vector<int> vis(1001, 0);
        
        queue<int> q;
        q.push(start);
        int level = 0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();
                
                if(curr == goal) return level;
                
                if(curr < 0 || curr > 1000 || vis[curr] == 1) continue;
                
                vis[curr] = 1;
                
                for(int i = 0; i < n; i++){
                    q.push(curr + nums[i]);
                    q.push(curr - nums[i]);
                    q.push(curr ^ nums[i]);
                }
            }
            level++;
        }
        return -1;
    }
};
