class Solution {
public:
    #define ll long long
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int> prefix(n + 1, 0);
        
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        
        vector<int> temp;
        
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                temp.push_back(prefix[j+1] - prefix[i]);   
            }
        }
        
        sort(temp.begin(),temp.end());
        
        ll sum = 0;
        
        int mod = 1e9 + 7;
        
        for(int i = left - 1; i <= right - 1; i++){
            sum = (sum + temp[i])%mod;
        }
        return sum;
    }
};
