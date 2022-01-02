class Solution {
public:
    int dp[101][101][101];
    int solve(int count, int l, int r, vector<int> &boxes){
        
        if(l > r){
            return 0;
        }
        
        if(dp[count][l][r] != -1){
            return dp[count][l][r];
        }
      
        int ans = (count + 1)*(count + 1) + solve(0, l + 1, r, boxes);
        
        for(int i = l + 1; i <= r; i++){
            if(boxes[l] == boxes[i]){
                ans = max(ans, solve(count + 1, i, r, boxes) + solve(0, l + 1, i - 1, boxes));   
            }
        }
        return dp[count][l][r] = ans;
    }
    int removeBoxes(vector<int>& boxes) {
        
        memset(dp, -1, sizeof(dp));
        int n = boxes.size();
        return solve(0, 0, n - 1, boxes);
    }
};
