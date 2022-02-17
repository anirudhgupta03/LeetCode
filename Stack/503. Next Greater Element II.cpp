//Ref: https://www.youtube.com/watch?v=RkG94TvnUFs
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> st;
        
        int n = nums.size();
        st.push(nums[n - 1]);
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < st.top()){
                st.push(nums[i]);
            }
            else{
                while(!st.empty() && nums[i] >= st.top()){
                    st.pop();
                }
                st.push(nums[i]);
            }
        }
        
        vector<int> res(n);
        
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] < st.top()){
                res[i] = st.top();
            }
            else{
                while(!st.empty() && nums[i] >= st.top()){
                    st.pop();
                }
                if(st.empty()){
                    res[i] = -1;
                }
                else{
                    res[i] = st.top();
                }
            }
            st.push(nums[i]);
        }
        return res;
    }
};
