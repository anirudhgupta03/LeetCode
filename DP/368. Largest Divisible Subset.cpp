//Method without altering the original array
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();

        vector<pair<int,int>> tnums(n);
        for(int i = 0; i < n; i++){
            tnums[i] = {nums[i], i};
        }
        sort(tnums.begin(), tnums.end());

        vector<int> dp(n, 1), hash(n);
        for(int i = 0; i < n; i++){
            hash[i] = i;
        }

        int maxLen = 1, maxInd = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if((tnums[i].first % tnums[j].first) == 0){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        hash[i] = j;
                    }
                }
            }
            if(dp[i] > maxLen){
                maxLen = dp[i];
                maxInd = i;
            }
        }

        vector<int> res;
        while(hash[maxInd] != maxInd){
            res.push_back(tnums[maxInd].second);
            maxInd = hash[maxInd];
        }
        res.push_back(tnums[maxInd].second);
        sort(res.begin(), res.end());
        
        for(int i = 0; i < res.size(); i++){
            res[i] = nums[res[i]];
        }
        return res;
    }
};

//LIS Variant
//Ref: https://www.youtube.com/watch?v=Wv6DlL0Sawg
//Method - 1
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        
        vector<int> dp[n];
        
        
        dp[0].push_back(0);
        
        int ans = 1;
        vector<int> res = {0};
      
        for(int i = 1; i < n; i++){
            int maxsize = 1;
            bool flag = false;
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    vector<int> v = dp[j];
                    v.push_back(i);
                    if(v.size() > maxsize){
                        flag = true;
                        dp[i] = v;
                        maxsize = v.size();
                    }
                }
            }
            if(!flag){
                dp[i] = {i};
            }
            if(dp[i].size() > ans){
                ans = dp[i].size();
                res = dp[i];
            }
        }
        vector<int> result;
        for(int i = 0; i < res.size(); i++){
            result.push_back(nums[res[i]]);
        }
        return result;
    }
};

//Method - 2
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        vector<int> dp[n];
        dp[0].push_back(nums[0]);
        
        vector<int> res = dp[0];
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[j].size() > dp[i].size()){
                        dp[i] = dp[j];
                    }
                }
            }
            dp[i].push_back(nums[i]);
            if(dp[i].size() > res.size()){
                res = dp[i];
            }
        }
        return res;
    }
};
