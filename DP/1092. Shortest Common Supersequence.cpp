//Method - 1
//Find LCS and then using that find SCS
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int len1 = str1.size(), len2 = str2.size();
        
        int dp[len1 + 1][len2 + 1];
        
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
        string LCS;
        
        while(i && j){
            if(str1[i - 1] == str2[j - 1]){
                LCS.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else{
                if(dp[i - 1][j] > dp[i][j - 1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        reverse(LCS.begin(), LCS.end());
        int len3 = LCS.size();
        
        string SCS;
        int ptr1 = 0, ptr2 = 0, ptr3 = 0;
        
        while(ptr3 < len3){
            
            while(ptr1 < len1 && str1[ptr1] != LCS[ptr3]){
                SCS.push_back(str1[ptr1]);
                ptr1++;
            }
            while(ptr2 < len2 && str2[ptr2] != LCS[ptr3]){
                SCS.push_back(str2[ptr2]);
                ptr2++;
            }
            while(ptr1 < len1 && ptr2 < len2 && ptr3 < len3 && str1[ptr1] == LCS[ptr3] && str2[ptr2] == LCS[ptr3]){
                SCS.push_back(LCS[ptr3]);
                ptr1++;
                ptr2++;
                ptr3++;
            }
        }
        while(ptr1 < len1){
            SCS.push_back(str1[ptr1]);
            ptr1++;
        }
        while(ptr2 < len2){
            SCS.push_back(str2[ptr2]);
            ptr2++;
        }
        return SCS;
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

//Method - 4
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

//Method - 5
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

//Method - 6
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
