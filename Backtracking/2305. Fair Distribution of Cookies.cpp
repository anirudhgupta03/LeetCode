class Solution {
public:
    void solve(vector<int> &vis, int count, vector<int> &cookies, vector<int> &sum, int &minSum, int k){
        
        if(count == vis.size() && k == 0){
            int maxSum = 0;
            for(int i = 0; i < sum.size(); i++){
                maxSum = max(maxSum, sum[i]);
            }
            minSum = min(minSum, maxSum);
            return;
        }
        if(k == 0 || count == vis.size()){
            return;
        }
        
        for(int i = 0; i < cookies.size(); i++){
            if(vis[i] == 0){
                vis[i] = 1;
                sum[k - 1] += cookies[i];
                solve(vis, count + 1, cookies, sum, minSum, k);
                solve(vis, count + 1, cookies, sum, minSum, k - 1);
                sum[k - 1] -= cookies[i];
                vis[i] = 0;
            }
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        
        int n = cookies.size();
        
        vector<int> vis(n, 0), sum(k, 0);
        
        int minSum = INT_MAX, count = 0;
        
        solve(vis, count, cookies, sum, minSum, k);
        
        return minSum;
    }
};
