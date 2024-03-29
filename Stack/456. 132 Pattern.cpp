//Ref1: https://www.youtube.com/watch?v=8nx5dxFuvLo
//Ref2: https://leetcode.com/problems/132-pattern/discuss/1541296/O(n)-or-C%2B%2B-or-Easy-to-understand
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> tmin(n);
        
        tmin[0] = nums[0];
        
        for(int i = 1; i < n; i++){
            tmin[i] = min(tmin[i-1], nums[i]);
        }
        
        stack<int> st;
        
        for(int i = n - 1; i >= 1; i--){
            if(nums[i] > tmin[i - 1]){
                while(!st.empty() && st.top() <= tmin[i - 1]){
                    st.pop();
                }
                
                if(!st.empty() && st.top() < nums[i]){
                    return true;
                }
                st.push(nums[i]);
            }
        }
        return false;
    }
};
