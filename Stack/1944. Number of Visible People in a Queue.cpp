class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        
        stack<int> st;
        int n = heights.size();
        
        st.push(heights[n - 1]);
        
        vector<int> res(n, 0);
        
        for(int i = n - 2; i >= 0; i--){
            while(!st.empty() && heights[i] > st.top()){
                res[i]++;
                st.pop();
            }
            if(st.size()) res[i]++;
            st.push(heights[i]);
        }
        return res;
    }
};
