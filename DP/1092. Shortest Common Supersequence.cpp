//Method - 1
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        
        int len1 = s1.size();
        int len2 = s2.size();
        
        int dp[len1+1][len2+1];
        
        for(int i = 0; i < len1 + 1; i++){
            for(int j = 0; j < len2 + 1; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        int i = len1, j = len2;
        string s;
        
        while(i > 0 && j > 0){
            
            if(s1[i-1] == s2[j-1]){
                s.push_back(s1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        
        reverse(s.begin(),s.end());
        
        int len3 = s.length();
        int p1 = 0, p2 = 0, p3 = 0;
        
        string ans;
        while(p1!= len1 && p2!= len2 && p3!= len3){
            
            if(s1[p1] == s[p3]){
                while(s2[p2]!=s[p3]){
                    ans.push_back(s2[p2]);
                    p2++;
                }
                ans.push_back(s[p3]);
                p1++;
                p2++;
                p3++;
            }
            else if(s2[p2] == s[p3]){
                while(s1[p1]!=s[p3]){
                    ans.push_back(s1[p1]);
                    p1++;
                }
                ans.push_back(s[p3]);
                p1++;
                p2++;
                p3++;
            }
            else{
                while(s1[p1]!=s[p3]){
                    ans.push_back(s1[p1]);
                    p1++;
                }
            }
        }
        
        if(p1!= len1){
            while(p1!=len1){
                ans.push_back(s1[p1]);
                p1++;
            }
        }
        if(p2!= len2){
            while(p2!=len2){
                ans.push_back(s2[p2]);
                p2++;
            }
        }
        return ans;
    }
};

//Method - 2
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

//Method - 3
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        
        int len1 = s1.size();
        int len2 = s2.size();
        
        string dp[len1+1][len2+1];
        
        for(int i = 0; i < len1 + 1; i++){
            for(int j = 0; j < len2 + 1; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = "";
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + s1[i-1];
                }
                else{
                    if(dp[i-1][j].size()>dp[i][j-1].size()){
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        
        int i = len1, j = len2;

        string s = dp[len1][len2];
        
        int len3 = s.length();
        int p1 = 0, p2 = 0, p3 = 0;
        
        string ans;
        while(p1!= len1 && p2!= len2 && p3!= len3){
            
            if(s1[p1] == s[p3]){
                while(s2[p2]!=s[p3]){
                    ans.push_back(s2[p2]);
                    p2++;
                }
                ans.push_back(s[p3]);
                p1++;
                p2++;
                p3++;
            }
            else if(s2[p2] == s[p3]){
                while(s1[p1]!=s[p3]){
                    ans.push_back(s1[p1]);
                    p1++;
                }
                ans.push_back(s[p3]);
                p1++;
                p2++;
                p3++;
            }
            else{
                while(s1[p1]!=s[p3]){
                    ans.push_back(s1[p1]);
                    p1++;
                }
            }
        }
        
        if(p1!= len1){
            while(p1!=len1){
                ans.push_back(s1[p1]);
                p1++;
            }
        }
        if(p2!= len2){
            while(p2!=len2){
                ans.push_back(s2[p2]);
                p2++;
            }
        }
        return ans;
    }
};

//Method - 4class Solution {
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
