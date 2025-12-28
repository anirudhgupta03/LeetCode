//Method - 1
//Find LCS and then using that find SCS
class Solution {
public:
    string findLCS(string& str1, string& str2){
        int len1 = str1.length(), len2 = str2.length();
        
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        
        for(int i = 0; i <= len1; i++){
            for(int j = 0; j <= len2; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(str1[i - 1] == str2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        int i = len1, j = len2;
        string lcs;
        
        while(i != 0 && j != 0){
            if(str1[i - 1] == str2[j - 1]){
                lcs.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else{
                if(dp[i - 1][j] > dp[i][j - 1]) i--;    
                else j--;
            }
        }
        
        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        
        string lcs = findLCS(str1, str2);
        int len1 = str1.length(), len2 = str2.length(), len3 = lcs.length();

        int i = 0, j = 0, k = 0;
        string scs;
        
        while(k < len3){
            while(i < len1 && str1[i] != lcs[k]){
                scs.push_back(str1[i]);
                i++;
            }
            while(j < len2 && str2[j] != lcs[k]){
                scs.push_back(str2[j]);
                j++;
            }
            if(i < len1 && str1[i] == lcs[k]) i++;
            if(j < len2 && str2[j] == lcs[k]) j++;
            scs.push_back(lcs[k]);
            k++;
        }
        
        while(i < len1){
            scs.push_back(str1[i]);
            i++;
        }
        
        while(j < len2){
            scs.push_back(str2[j]);
            j++;
        }
        return scs;
    }
};

//Method - 2
//Directly find SCS
//Ref: https://www.youtube.com/watch?v=VDhRg-ZJTuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=30
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n1 = str1.size(), n2 = str2.size();
        
        int dp[n1+1][n2+1];
        
        for(int i = 0; i <= n1; i++){
            for(int j = 0; j <= n2; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        string scs;
        int i = n1, j = n2;
        
        while(i != 0 && j != 0){
            
            if(str1[i-1] == str2[j-1]){
                scs.push_back(str1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    scs.push_back(str1[i-1]);
                    i--;
                }
                else{
                    scs.push_back(str2[j-1]);
                    j--;
                }
            }
        }
        
        while(i){
            scs.push_back(str1[i-1]);
            i--;
        }
        while(j){
            scs.push_back(str2[j-1]);
            j--;
        }
        reverse(scs.begin(),scs.end());
        return scs;
    }
};

//Method - 3
//Time Complexity - O(n*m)
//Space Complexity - O(n*m)
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
        
        cout << lcs << endl;
        
        int p1 = 0, p2 = 0, p3 = 0;
        
        string scs;
        
        while(p3 < lcs.size()){
            
            while(str1[p1] != lcs[p3] && p1 < n){
                scs.push_back(str1[p1]);
                p1++;
            }
            
            while(str2[p2] != lcs[p3] && p2 < m){
                scs.push_back(str2[p2]);
                p2++;
            }
    
            scs.push_back(lcs[p3]);
            p1++;
            p2++;
            p3++;
        }
        
        while(p1 < n){
            scs.push_back(str1[p1]);
            p1++;
        }
        while(p2 < m){
            scs.push_back(str2[p2]);
            p2++;
        }
        return scs;
    }
};
