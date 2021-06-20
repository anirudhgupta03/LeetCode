//Ref: https://leetcode.com/problems/minimum-absolute-difference-queries/discuss/1284358/C%2B%2B-Binary-search
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
