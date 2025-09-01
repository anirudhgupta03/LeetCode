//Ref: https://www.youtube.com/watch?v=h4aBagy4Uok&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=9
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
