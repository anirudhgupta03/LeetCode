//Method - 1
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        
        unordered_set<string> us;
        
        for(int i = 0; i < wordDict.size(); i++){
            us.insert(wordDict[i]);
        }
        
        int dp[n];
        memset(dp,0,sizeof(dp));
        
        for(int i = 0; i < n; i++){
            for(int j = i; j >= 0; j--){
               
                string temp = s.substr(j,i-j+1);
                if(us.find(temp) != us.end()){
                    if(j >= 1)
                    dp[i] = dp[i] || dp[j-1];
                    else
                    dp[i] = 1;
                }
            }
        }
        return dp[n-1];
    }
};

//Method - 2
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string,int> umap;
        
        for(auto &x: wordDict){
            umap[x]++;
        }
        
        int n = s.size();
        bool dp[n];
        memset(dp,false,sizeof(dp));
        
        for(int i = 0; i < n; i++){
            for(int j = i; j >= 0; j--){
                if(umap[s.substr(j, i - j + 1)]){
                    if(j == 0 || dp[j - 1]){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n - 1];
    }
};
