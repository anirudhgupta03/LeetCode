class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        int maxDist = 0;
        
        for(int i = 0; i < nums1.size(); i++){
            
            int lo = i + 1, hi = nums2.size() - 1, ans = i;
            
            while(lo <= hi){
                
                int mid = (lo + hi)/2;
                
                if(nums2[mid] >= nums1[i]){
                    ans = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            maxDist = max(maxDist, ans - i);
        }
        return maxDist;
    }
};
