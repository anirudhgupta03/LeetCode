//Using Maximum Area Histogram
//Method - 1
class Solution {
public:
    int mah(vector<int> height, int n){
        
        vector<int> nsl;
        vector<int> nsr;
        
        nsl.push_back(-1);
        
        stack<pair<int,int>> s;
        
        s.push({height[0],0});
        
        for(int i = 1; i < n; i++){
            
            if(s.top().first < height[i]){
                nsl.push_back(s.top().second);
            }
            else{
                while(!s.empty() && height[i] <= s.top().first){
                    s.pop();
                }
                
                if(s.empty()){
                    nsl.push_back(-1);
                }
                else{
                    nsl.push_back(s.top().second);
                }
            }
            s.push({height[i],i});
        }
        
        while(s.size()){
            s.pop();
        }
        
        nsr.push_back(n);
        
        s.push({height[n-1],n-1});
        
        for(int i = n - 2; i >= 0; i--){
            
            if(s.top().first < height[i]){
                nsr.push_back(s.top().second);
            }
            else{
                
                while(!s.empty() && s.top().first >= height[i]){
                    s.pop();
                }
                
                if(s.empty()){
                    nsr.push_back(n);
                }
                else{
                    nsr.push_back(s.top().second);
                }
            }
            s.push({height[i],i});
        }
        
        reverse(nsr.begin(),nsr.end());
        
        int mareah = INT_MIN;
        
        for(int i = 0; i < n; i++){
            
            int larea = (i-nsl[i] - 1)*(height[i]);
            int rarea = (nsr[i] - i -1)*(height[i]);
            
            if(larea + rarea + height[i] > mareah){
                mareah = larea + rarea + height[i];
            }
        }
        
        return mareah;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        
        if(m == 0){
            return 0;
        }
        int n = matrix[0].size();
        
        vector<vector<int>> histogram(m,vector<int>(n));
        
        for(int j = 0; j < n; j++){
            histogram[0][j] = matrix[0][j]-48;
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0'){
                    histogram[i][j] = 0;
                }
                else{
                    histogram[i][j] = histogram[i-1][j] + 1;
                }
            }
        }
        
        int maxarea = INT_MIN;
        
        for(int i = 0; i < m; i++){
            maxarea = max(mah(histogram[i],n),maxarea);
        }
        
        return maxarea;
    }
};

//Method - 2
class Solution {
public:
    int findMaxArea(vector<int> &v){
        
        int n = v.size();
        
        vector<int> nsl(n), nsr(n);
        
        stack<int> st;
        
        nsl[0] = -1;
        st.push(0);
        
        for(int i = 1; i < n; i++){
            if(v[i] > v[st.top()]){
                nsl[i] = st.top();
            }
            else{
                while(!st.empty() && v[st.top()] >= v[i]){
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
        
        while(!st.empty()){
            st.pop();
        }
        
        st.push(n - 1);
        nsr[n - 1] = n;
        
        for(int i = n - 2; i >= 0; i--){
            if(v[i] > v[st.top()]){
                nsr[i] = st.top();
            }
            else{
                while(!st.empty() && v[st.top()] >= v[i]){
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
        
        vector<vector<int>> heights(m, vector<int>(n, 0));
        
        for(int j = 0; j < n; j++){
            heights[0][j] = matrix[0][j] == '1' ? 1 : 0;
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                heights[i][j] = matrix[i][j] == '0' ? 0 : 1 + heights[i - 1][j];
            }
        }
        
        int maxArea = 0;
        
        for(int i = 0; i < m; i++){
            maxArea = max(maxArea, findMaxArea(heights[i]));
        }
        
        return maxArea;
    }
};
