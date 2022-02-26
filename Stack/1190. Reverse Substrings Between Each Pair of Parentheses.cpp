class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] >= 'a' && s[i] <= 'z'){
                st.push(s[i]);
            }
            else{
                string temp;
                while(st.top() != '('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(int i = 0; i < temp.size(); i++){
                    st.push(temp[i]);
                }
            }
        }
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
