//Method - 1
class Solution {
public:
    int solve(int ind, int prev, string ring, string key, vector<vector<int>> &dp){
        
        if(ind == key.size()){
            return 0;
        }
        
        if(dp[ind][prev] != -1){
            return dp[ind][prev];
        }
        
        int minsteps = INT_MAX;
        
        for(int i = 0; i < ring.size(); i++){
            if(ring[i] == key[ind]){
                if(i >= prev){
                    int n = ring.size();
                    int temp = abs(i - prev - n);
                    minsteps = min(minsteps, solve(ind + 1, i, ring, key, dp) + i - prev + 1);
                    minsteps = min(minsteps, solve(ind + 1, i, ring, key, dp) + temp + 1);
                }
                else{
                    int n = ring.size();
                    int temp = abs(prev - i - n);
                    minsteps = min(minsteps, solve(ind + 1, i, ring, key, dp) + temp + 1);
                    minsteps = min(minsteps, solve(ind + 1, i, ring, key, dp) + abs(i - prev) + 1);
                }
            }
        }
        return dp[ind][prev] = minsteps;
    }
    int findRotateSteps(string ring, string key) {
        
        int len1 = ring.size(), len2 = key.size();
        
        int minsteps = INT_MAX, steps = 0;
        
        vector<vector<int>> dp(len2, vector<int>(len1,-1));
        
        return solve(0, 0, ring, key, dp);
    }
};

//Method - 2
class Solution {
public:
    int solve(int ind1, int ind2, string &ring, string &key, vector<vector<int>> &dp){
        
        if(ind2 == key.size()){
            return 0;
        }
        
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        
        int minSteps = INT_MAX;
        
        if(ring[ind1] == key[ind2]){
            minSteps = min(minSteps, solve(ind1, ind2 + 1, ring, key, dp) + 1);
        }
        else{
            for(int i = ind1 + 1; i < ring.size() + ind1; i++){
                if(ring[i % ring.size()] == key[ind2]){
                    minSteps = min(minSteps, solve(i % ring.size(), ind2 + 1, ring, key, dp) + i - ind1 + 1);
                }
            }
            
            for(int i = ind1 - 1; i >= 0; i--){
                if(ring[i] == key[ind2]){
                    minSteps = min(minSteps, solve(i, ind2 + 1, ring, key, dp) + ind1 - i + 1);
                }
            }
            
            for(int i = ring.size() - 1; i >= ind1 + 1; i--){
                if(ring[i] == key[ind2]){
                    minSteps = min(minSteps, solve(i, ind2 + 1, ring, key, dp) + ind1 + (int)ring.size() - i + 1);
                }
            }
        }
        return dp[ind1][ind2] = minSteps;
    }
    int findRotateSteps(string ring, string key) {
        
        int len1 = ring.size(), len2 = key.size();
        
        vector<vector<int>> dp(len1, vector<int>(len2, -1));
        
        return solve(0, 0, ring, key, dp);
    }
};
