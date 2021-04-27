class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n = str1.size(), m = str2.size();
        
        string dp[n+1][m+1];
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                
                if(i == 0 || j == 0){
                    dp[i][j] = "";
                }
                else if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + str1[i-1];
                }
                else{
                    if(dp[i-1][j].size() > dp[i][j-1].size()){
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        
        string lcs = dp[n][m];

        int p1 = 0, p2 = 0, p3 = 0;
        
        int p = lcs.size();
        
        string scs;
        
        while(p1 != n && p2 != m && p3 != p){
            
            if(str1[p1] == lcs[p3]){
                while(str2[p2] != lcs[p3] && p2 < m){
                    scs.push_back(str2[p2]);
                    p2++;
                }
                scs.push_back(lcs[p3]);
                p1++;
                p2++;
                p3++;
            }
            else{
                while(str1[p1] != lcs[p3] && p1 < n){
                    scs.push_back(str1[p1]);
                    p1++;
                }
            }
        }
        
        while(p1 != n){
            scs.push_back(str1[p1]);
            p1++;
        }
        while(p2 != m){
            scs.push_back(str2[p2]);
            p2++;
        }
        
        return scs;
    }
};
