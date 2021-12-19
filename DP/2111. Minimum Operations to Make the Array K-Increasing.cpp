class Solution {
public:
    int lengthOfLIS(vector<int> &nums){
        
        int n = nums.size();
        vector<int> v;
        v.push_back(nums[0]);
        
        for(int i = 1; i < n; i++){
            if(nums[i] >= v.back()) v.push_back(nums[i]);
            else{
                int idx = upper_bound(v.begin(),v.end(),nums[i]) - v.begin();
                v[idx] = nums[i];
            }
        }
        return n - v.size();
    }
    int kIncreasing(vector<int>& arr, int k) {
        
        int ans = 0;
        int n = arr.size();
        
        for(int i = 0; i < k; i++){
            vector<int> tmp;
            for(int j = i; j < n; j += k) tmp.push_back(arr[j]);
            int curr = lengthOfLIS(tmp);
            ans += curr;
        }
        
        return ans;
    }
};
