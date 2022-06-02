//Ref: https://www.youtube.com/watch?v=ym93rTBR4j8
//Method - 1
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

//Method - 2
class Solution {
public:
    int numberOfPairsWithDiffMid(int diff, vector<int> &nums){
        
        int lo = 0, hi = 0, count = 0;
        
        while(hi < nums.size()){
            
            if(nums[hi] - nums[lo] <= diff){
                hi++;
            }
            else{
                while(lo <= hi && nums[hi] - nums[lo] > diff){
                    count += hi - lo - 1;
                    lo++;
                }
                hi++;
            }
        }
        count += (hi - lo)*(hi - lo -1)/2;
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        int lo = 0, hi = nums[n - 1] - nums[0], ans;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(numberOfPairsWithDiffMid(mid, nums) >= k){
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
