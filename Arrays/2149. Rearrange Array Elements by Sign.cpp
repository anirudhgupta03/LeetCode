class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n, 0);

        int indexpos = 0, indexneg = 1;

        for(int ele: nums){
            if(ele > 0){
                ans[indexpos] = ele;
                indexpos += 2;
            }
            else if(ele < 0){
                ans[indexneg] = ele;
                indexneg += 2;
            }
        }
        return ans;
    }
};
