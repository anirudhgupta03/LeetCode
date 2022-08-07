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
//Top-Down
//TC: O(len1*len2)
//SC: O(len1*len2) + Auxilliary Stack Space
class Solution {
public:
    int solve(int ind1, int ind2, int ind3, string &s1, string &s2, string &s3, vector<vector<int>> &dp){
        
        if(ind3 == s3.size()){
            return true;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        if(ind1 < s1.size() && s1[ind1] == s3[ind3]){
            bool flag = solve(ind1 + 1,ind2, ind3 + 1, s1, s2, s3, dp);
            if(flag) return dp[ind1][ind2] = 1;
        }
        if(ind2 < s2.size() && s2[ind2] == s3[ind3]){
            bool flag = solve(ind1, ind2 + 1, ind3 + 1, s1, s2, s3, dp);
            if(flag) return dp[ind1][ind2] = 1;
        }
        return dp[ind1][ind2] = 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        
        if(len1 + len2 != len3){
            return false;
        }
        
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, -1)); 
        
        return solve(0, 0, 0, s1, s2, s3, dp);
    }
};

//Method - 3
//Bottom-Up
//TC: O(len1*len2)
//SC: O(len1*len2)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        
        if(len1 + len2 != len3){
            return false;
        }
        
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0)); 
        
        for(int ind1 = len1; ind1 >= 0; ind1--){
            for(int ind2 = len2; ind2 >= 0; ind2--){
                if(ind1 + ind2 == len3){
                    dp[ind1][ind2] = 1;
                }
                else{
                    if(ind1 < len1 && s1[ind1] == s3[ind1 + ind2]){
                        bool flag = dp[ind1 + 1][ind2];
                        if(flag){
                            dp[ind1][ind2] = 1;
                            continue;
                        }
                    }
                    if(ind2 < len2 && s2[ind2] == s3[ind1 + ind2]){
                        bool flag = dp[ind1][ind2 + 1];
                        if(flag){
                            dp[ind1][ind2] = 1;
                            continue;
                        }
                    }
                    dp[ind1][ind2] = 0;
                }
            }
        }
        return dp[0][0];
    }
};

//Method - 4
//Bottom-Up
//TC: O(len1*len2)
//SC: O(len2)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        
        if(len1 + len2 != len3){
            return false;
        }
        
        vector<int> pre(len2 + 1), curr(len2 + 1);
        
        pre[len2] = 1;
        
        for(int j = len2 - 1; j >= 0; j--){
            if(s2[j] == s3[len1 + j]){
                if(pre[j + 1]){
                    pre[j] = 1;
                }
                else{
                    pre[j] = 0;
                }
            }
        }
        
        for(int ind1 = len1 - 1; ind1 >= 0; ind1--){
            for(int ind2 = len2; ind2 >= 0; ind2--){
                if(ind1 < s1.size() && s1[ind1] == s3[ind1 + ind2]){
                    bool flag = pre[ind2];
                    if(flag){
                        curr[ind2] = 1;
                        continue;
                    }
                }
                if(ind2 < s2.size() && s2[ind2] == s3[ind1 + ind2]){
                    bool flag = curr[ind2 + 1];
                    if(flag){
                        curr[ind2] = 1;
                        continue;
                    }
                }
                curr[ind2] = 0;
            }
            pre = curr;
        }
        return pre[0];
    }
};
