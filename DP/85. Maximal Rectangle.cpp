class Solution {
public:
    int findMaxArea(vector<int> &v){
        
        int n = v.size();
        
        stack<int> st;
        
        vector<int> nsl(n),nsr(n);
        
        nsl[0] = -1;
        st.push(0);
        
        for(int i = 1; i < n; i++){
            if(v[i] > v[st.top()]){
                nsl[i] = st.top();
            }
            else{
                while(!st.empty() && v[i] <= v[st.top()]){
                    st.pop();
                }
                if(st.empty()){
                    nsl[i] = -1;
                }
                else{
                    nsl[i] = st.top();
                }
            }
            st.push(i);
        }
        
        nsr[n - 1] = n;
        while(!st.empty()) st.pop();
        
        st.push(n - 1);
        
        for(int i = n - 2; i >= 0; i--){
            if(v[i] > v[st.top()]){
                nsr[i] = st.top();
            }
            else{
                while(!st.empty() && v[i] <= v[st.top()]){
                    st.pop();
                }
                if(st.empty()){
                    nsr[i] = n;
                }
                else{
                    nsr[i] = st.top();
                }
            }
            st.push(i);
        }
        
        int maxArea = 0;
        
        for(int i = 0; i < n; i++){
            maxArea = max(maxArea, (nsr[i] - nsl[i] - 1)*v[i]);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        
        vector<vector<int>> grid(m, vector<int>(n));
        
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == '1') grid[0][j] = 1;
            else grid[0][j] = 0;
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1') grid[i][j] = 1 + grid[i - 1][j];
                else{
                    grid[i][j] = 0;
                }
            }
        }
        
        int maxArea = 0;
        
        for(int i = 0; i < m; i++){
            maxArea = max(maxArea, findMaxArea(grid[i]));
        }
        return maxArea;
    }
};
