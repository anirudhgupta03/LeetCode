class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        reverse(nums2.begin(),nums2.end());
        
        int ans = 0;
        
        for(int i = 0; i < nums1.size(); i++){
            
            int p = lower_bound(nums2.begin(),nums2.end(),nums1[i]) - nums2.begin();
            
            if(p == nums2.size()){
                continue;
            }
            
            int end = nums2.size() - p - 1;
            
            if(end < i){
                continue;
            }
            
            ans = max(ans,end-i);
        }
        
        return ans;
    }
};
