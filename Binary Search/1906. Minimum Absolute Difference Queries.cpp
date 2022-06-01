//Ref: https://leetcode.com/problems/minimum-absolute-difference-queries/discuss/1284358/C%2B%2B-Binary-search
//Method - 1
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> cnt[101];
        
        for(int i = 0; i < nums.size(); i++){
            cnt[nums[i]].push_back(i);
        }
        
        int q = queries.size();
        
        vector<int> ans(q);
        
        for(int i = 0; i < q; i++){
            
            int lo = queries[i][0], hi = queries[i][1];
            
            vector<int> temp;
            
            for(int j = 1; j < 101; j++){
                
                int lb = lower_bound(cnt[j].begin(),cnt[j].end(),lo) - cnt[j].begin();
                
                if(lb < cnt[j].size() && cnt[j][lb] <= hi){
                    temp.push_back(j);
                }
            }
            
            if(temp.size() == 1){
                ans[i] = -1;
                continue;
            }
            
            int t = INT_MAX;
            for(int k = 1; k < temp.size(); k++){
                t = min(t,temp[k]-temp[k-1]);
            }
            
            ans[i] = t;
        }
        return ans;
    }
};

//Method - 2
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<int> res;
        
        int n = nums.size(), maxval = *max_element(nums.begin(), nums.end());
        
        vector<vector<int>> prefix(n + 1, vector<int>(maxval + 1, 0));
        
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1];
            prefix[i][nums[i - 1]] = 1 + prefix[i - 1][nums[i - 1]];
        }
        
        for(int i = 0; i < queries.size(); i++){
            
            vector<int> v(maxval + 1);
            
            for(int j = 0; j <= maxval; j++){
                v[j] = prefix[queries[i][1] + 1][j] - prefix[queries[i][0]][j];
            }
            
            int minDiff = INT_MAX, pre = -1;
            
            for(int j = 1; j <= maxval; j++){
                if(v[j]){
                    if(pre != -1){
                        minDiff = min(minDiff, j - pre);
                    }
                    pre = j;
                }
            }
            if(minDiff == INT_MAX) res.push_back(-1);
            else res.push_back(minDiff);
        }
        return res;
    }
};
