class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        int i = 0, j = 0;
        
        while(i < pushed.size() && j < popped.size()){
            if(!st.empty() && (st.top() == popped[j])){
                st.pop();
                j++;
            }
            else{
                st.push(pushed[i]);
                i++;
            }
        }
        while(!st.empty() && st.top() == popped[j]){
            st.pop();
            j++;
        }
        if(j == popped.size()){
            return true;
        }
        return false;
    }
};
