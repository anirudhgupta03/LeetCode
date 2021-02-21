class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        
        int n1 = A.size(), n2 = B.size();
        
        int dp[n1+1][n2+1];
        
        for(int i = 0; i < n1 + 1; i++){
            for(int j = 0; j < n2 + 1; j++){
                
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(A[i-1] == B[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};
