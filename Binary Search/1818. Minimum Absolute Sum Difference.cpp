//Ref: https://leetcode.com/problems/minimum-absolute-sum-difference/discuss/1141920/C%2B%2B-or-O(nlogn)-or-lowerbound
//Ref: https://leetcode.com/problems/minimum-absolute-sum-difference/discuss/1141337/Short-and-Easy-w-Explanation-or-Binary-Search-solution
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
