class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        
        vector<vector<string>> res(n);
        
        vector<string> ans;
        
        int dp[n];
        memset(dp,0,sizeof(dp));
        
        unordered_set<string> us;
        
        for(int i = 0; i < wordDict.size(); i++){
            us.insert(wordDict[i]);
        }
        
        for(int i = 0; i < n; i++){
            
            for(int j = i; j >= 0; j--){
                
                string t = s.substr(j,i-j+1);
                
                if(us.find(t) != us.end()){
                    
                    if(j >= 1 && dp[j-1]){
                        for(int k = 0; k < res[j-1].size(); k++){
                            res[i].push_back(res[j-1][k] + " " + t);
                        }
                        dp[i] = 1;
                    }
                    else if(j < 1){
                        res[i].push_back(t);
                        dp[i] = 1;
                    }
                }
            }
        }
        
        for(int i = 0; i < res[n-1].size(); i++){
            ans.push_back(res[n-1][i]);
        }
        
        return ans;
    }
};
