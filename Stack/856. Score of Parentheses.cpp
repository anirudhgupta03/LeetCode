//Ref: https://www.youtube.com/watch?v=rWsv46ME6lI
class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int> st;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(-1);
            }
            else if(s[i] == ')'){
                if(st.top() == -1){
                    st.pop();
                    st.push(1);
                }
                else{
                    int sum = 0;
                    while(st.top() != -1){
                        sum += st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2*sum);
                }
            }
        }
        int res = 0;
        while(st.size()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};
