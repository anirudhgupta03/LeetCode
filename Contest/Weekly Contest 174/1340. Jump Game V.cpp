//DP + Memoization
class Solution {
public:
    
    int solve(int curr, int n, int d, vector<int> &dp, vector<int> &vis, vector<int> &arr){
        
        vis[curr] = 1;
        
        for(int i = curr - 1; i >= max(0,curr-d); i--){
            
            if(arr[i] >= arr[curr]){            //If any building has height greater than or equal to the current building height then we can stop as we won't be able to
                                                //and other buildings before it 
                break;
            }
            else if(arr[i] < arr[curr]){
                
                if(vis[i] == 1){                //If the building has already been visited then we just need to consider the number of possible jumps which can be made from it
                    dp[curr] = max(dp[curr],dp[i]+1);
                }
                else{
                    dp[curr] = max(dp[curr],solve(i,n,d,dp,vis,arr)+1); //else if the building is not visited then we will calculate the possible jumps from that buliding
                                                                        //using recursion +  memoization
                }
            }
        }
        for(int i = curr + 1; i <= min(n-1,curr+d); i++){
            
            if(arr[i] >= arr[curr]){
                break;
            }
            else if(arr[i] < arr[curr]){
                
                if(vis[i] == 1){
                    dp[curr] = max(dp[curr],dp[i]+1);
                }
                else{
                    dp[curr] = max(dp[curr],solve(i,n,d,dp,vis,arr)+1);
                }
            }
        }
        return dp[curr];
    }
    int maxJumps(vector<int>& arr, int d) {
        
        int n = arr.size();
        
        vector<int> vis(n,0);
        vector<int> dp(n,1);
            
        for(int i = 0;  i< arr.size(); i++){
            
            if(vis[i] == 0){
                //cout << i << " ";
                solve(i,n,d,dp,vis,arr);
            }
        }
        cout << endl;
        
        int ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            //cout << dp[i] << " ";
            ans = max(ans,dp[i]);
        }
        //cout << endl;
        return ans;
    }
};
