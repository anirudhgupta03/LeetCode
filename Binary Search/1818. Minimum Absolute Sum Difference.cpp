//Ref: https://leetcode.com/problems/minimum-absolute-sum-difference/discuss/1141920/C%2B%2B-or-O(nlogn)-or-lowerbound
//Ref: https://leetcode.com/problems/minimum-absolute-sum-difference/discuss/1141337/Short-and-Easy-w-Explanation-or-Binary-Search-solution
//Method - 1
#define ll long long
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res;
        
        res = nums1;
        
        sort(res.begin(),res.end());
        
        ll origdiff = 0, n = nums1.size();
        
        for(int i = 0; i < n; i++)
        {
            origdiff = (origdiff + abs(nums1[i]-nums2[i]));
        }
        
        //sort(nums1.begin(),nums1.end());
        
        ll mindiff = origdiff;
        
        for(int i = 0; i < n; i++)
        {
            
            int ind = lower_bound(res.begin(),res.end(),nums2[i]) - res.begin();
            
            if(ind >= 0 && ind < n){
                ll newdiff = (origdiff - abs(nums1[i]-nums2[i]) + abs(res[ind]-nums2[i]));
                
                if(newdiff < mindiff){
                    mindiff = newdiff;
                }
            }
            
            ind--;
            if(ind >= 0 && ind < n){
                ll newdiff = (origdiff - abs(nums1[i]-nums2[i]) + abs(res[ind]-nums2[i]));
                
                if(newdiff < mindiff){
                    mindiff = newdiff;
                }
            }
            
        }
        return mindiff % 1000000007;
    }
};

//Method - 2
class Solution {
public:
    #define ll long long
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> nums3 = nums1;
        
        ll mod = 1e9 + 7, n = nums1.size(), minDiff = 0, ansDiff = 0;
        
        for(int i = 0; i < n; i++){
            minDiff = minDiff + abs(nums1[i] - nums2[i]);
        }
        
        ansDiff = minDiff;
        
        sort(nums1.begin(), nums1.end());
        
        for(int i = 0; i < nums2.size(); i++){
            
            int lo = 0, hi = n - 1;
            int ans = n;
            
            while(lo <= hi){
                int mid = (lo + hi)/2;
                if(nums1[mid] >= nums2[i]){
                    ans = mid;
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }
            
            if(ans == n){
                ll diff =(minDiff - abs(nums3[i] - nums2[i])  + abs(nums2[i] - nums1[ans - 1]));
                ansDiff = min(ansDiff, diff);
            }
            else if(ans == 0){ 
                ll diff =(minDiff - abs(nums3[i] - nums2[i]) + abs(nums2[i] - nums1[ans]));
                ansDiff = min(ansDiff, diff);
            }
            else{
                ll diff1 =(minDiff - abs(nums3[i] - nums2[i]) + abs(nums2[i] - nums1[ans - 1]));
                ll diff2 =(minDiff - abs(nums3[i] - nums2[i]) + abs(nums2[i] - nums1[ans]));
                
                ansDiff = min(ansDiff, diff1);
                ansDiff = min(ansDiff, diff2);
            }
        }
        return ansDiff % mod;
    }
};
