class Solution {
public:
    #define ll long long
    long long countExcellentPairs(vector<int>& nums, int k) {
        
        unordered_set<int> us;
        for(int i = 0; i < nums.size(); i++){
            us.insert(nums[i]);
        }
        
        vector<int> nb;
        
        for(auto &x: us){
            int curr = x;
            int count = 0;
            while(curr){
                if(curr % 2 == 1) count++;
                curr /= 2;
            }
            nb.push_back(count);
        }
        sort(nb.begin(), nb.end());
        
        ll ans = 0;
        
        for(int i = 0; i < nb.size(); i++){
            int ind = lower_bound(nb.begin(), nb.end(), k - nb[i]) - nb.begin();
            
            ans += nb.size() - ind;
        }
        return ans;
    }
};
