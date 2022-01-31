//Ref: https://www.youtube.com/watch?v=7Cz91Uj0VCU
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        
        queue<int> q;
        q.push(start);
        
        vector<int> vis(n, 0);
        
        while(!q.empty()){
            int ind = q.front();
            q.pop();
            
            if(arr[ind] == 0){
                return true;
            }
            if(vis[ind]) continue;
            vis[ind] = 1;
            
            int fwd = ind + arr[ind];
            int bwd = ind - arr[ind];
            
            if(fwd >= 0 && fwd < arr.size()) q.push(fwd);
            if(bwd >= 0 && bwd < arr.size()) q.push(bwd);
        }
        return false;
    }
};
