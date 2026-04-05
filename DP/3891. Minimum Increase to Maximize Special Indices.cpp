#define ll long long
class Solution {
public:
    unordered_map<int , pair<ll , ll>> dp;
    pair<ll, ll> findOperations(int ind, vector<int> &nums){
        
        if(ind >= nums.size() - 1){
            return {0, 0};
        }

        if(dp.find(ind) != dp.end()){
            return dp[ind];
        }
        
        int val1 = nums[ind - 1], val2 = nums[ind], val3 = nums[ind + 1];

        long long operations = INT_MAX;

        long long op1 = 0;
        if(val2 <= val1){
            op1 += abs(val2 - val1) + 1;
            val2 = val1 + 1;
        }
        if(val2 <= val3){
            op1 += abs(val2 - val3) + 1;
            val2 = val3 + 1;
        }

        auto take = findOperations(ind + 2, nums);
        take.first += 1;
        take.second += op1;

        auto skip = findOperations(ind + 1, nums);

        if(take.first > skip.first || take.first == skip.first && take.second < skip.second){
            return dp[ind] = take;
        }

        return dp[ind] = skip;
    }
    long long minIncrease(vector<int>& nums) {

        int n = nums.size();
        
        return findOperations(1, nums).second;
    }
};
