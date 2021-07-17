class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector<int> ngr(n);
        
        ngr[n-1] = n-1;
        
        stack<int> st;
        st.push(n-1);
        
        for(int i = n - 2; i >= 0; i--){
            
            if(temperatures[i] < temperatures[st.top()]){
                ngr[i] = st.top();
            }
            else{
                
                while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                    st.pop();
                }
                
                if(!st.empty()){
                    ngr[i] = st.top();
                }
                else{
                    ngr[i] = i;
                }
            }
            st.push(i);
        }
        
        for(int i = 0; i < n; i++){
            ngr[i] = ngr[i] - i;
        }
        return ngr;
    }
};
