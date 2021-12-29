//Ref: https://www.youtube.com/watch?v=ym93rTBR4j8
class Solution {
public:
    int countOfPairDistance(vector<int> &nums, int diff){
        
        int count = 0;
        int j = 1;
        for(int i = 0; i < nums.size(); i++){
            while(j < nums.size() && nums[j] - nums[i] <= diff) j++;
            j--;
            int x = (j - i);
            count += x;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        int lo = 0, hi = nums[n - 1] - nums[0];
        
        int ans;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(countOfPairDistance(nums, mid) >= k){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};
