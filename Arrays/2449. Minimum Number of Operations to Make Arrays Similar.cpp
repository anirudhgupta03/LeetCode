class Solution {
public:
    #define ll long long
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        
        int n = target.size();
        
        vector<int> odd, oddTarget, even, evenTarget;
        
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0){
                even.push_back(nums[i]);
            }
            else{
                odd.push_back(nums[i]);
            }
            
            if(target[i] % 2 == 0){
                evenTarget.push_back(target[i]);
            }
            else{
                oddTarget.push_back(target[i]);
            }
        }
        
        ll cnt = 0;
        
        for(int i = 0; i < even.size(); i++){
            cnt += (abs(even[i] - evenTarget[i]))/2;
        }
        for(int i = 0; i < odd.size(); i++){
            cnt += (abs(odd[i] - oddTarget[i]))/2;
        }
        return cnt/2;
    }
};
