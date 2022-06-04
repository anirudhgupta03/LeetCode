//Method - 1
class Solution {
    unordered_map<string,bool> mem;
    bool check(string s1,string s2,string s3,int len1,int len2,int len3,int p1,int p2,int p3){
        
        if(p3 == len3){
            return (p1 == len1 && p2 == len2) ? true : false;
        }
        
        string key = to_string(p1) + "*" + to_string(p2) + "*" + to_string(p3);
        
        if(mem.find(key)!=mem.end()){
            return mem[key];
        }
        
        if(p1 == len1){
            if(s2[p2] == s3[p3]){
                return mem[key] = check(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1);
            }
            else{
                return mem[key] = false;
            }
        }
        if(p2 == len2){
            if(s1[p1] == s3[p3]){
                return mem[key] = check(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1);
            }
            else{
                return mem[key] = false;
            }
        }
        
        bool one = false, two = false;
        
        if(s1[p1] == s3[p3]){
            one = check(s1,s2,s3,len1,len2,len3,p1+1,p2,p3+1);
        }
        if(s2[p2] == s3[p3]){
            two = check(s1,s2,s3,len1,len2,len3,p1,p2+1,p3+1);
        }
        return mem[key] = one || two;
    }
public:
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        
        if(len1 + len2 != len3){
            return false;
        }
        
        return check(s1,s2,s3,len1,len2,len3,0,0,0);
    }
};

//Method - 2
class Solution {
public:
    int len1, len2, len3;
    string str1, str2, str3;
    bool solve(int ind1, int ind2, int ind3, vector<vector<int>> &dp){
        
        if(ind1 == len1 && ind2 == len2){
            return true;
        }
        
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        
        if(ind1 == len1){
            if(str2[ind2] == str3[ind3]){
                bool flag = solve(ind1, ind2 + 1, ind3 + 1, dp);
                if(flag) return dp[ind1][ind2] = true;
            }
            else{
                return dp[ind1][ind2] = false;
            }
        }
        
        if(ind2 == len2){
            if(str1[ind1] == str3[ind3]){
                bool flag = solve(ind1 + 1, ind2, ind3 + 1, dp);
                if(flag) return dp[ind1][ind2] = true;
            }
            else{
                return dp[ind1][ind2] = false;
            }
        }
        
        if(str1[ind1] == str3[ind3]){
            bool flag = solve(ind1 + 1, ind2, ind3 + 1, dp);
            if(flag) return dp[ind1][ind2] = true;
        }
        
        if(str2[ind2] == str3[ind3]){
            bool flag = solve(ind1, ind2 + 1, ind3 + 1, dp);
            if(flag) return dp[ind1][ind2] = true;
        }
        
        return dp[ind1][ind2] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        str1 = s1, str2 = s2, str3 = s3;
        
        if(len1 + len2 != len3){
            return false;
        }
        
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, -1));
        
        return solve(0,0,0,dp);
    }
};
