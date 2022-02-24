//Method - 1
//TC - O(N)
//SC - O(N)
class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else{
                    st.push(')');
                }
            }
            else{
                st.push('(');
            }
        }
        return st.size();
    }
};

//Method - 2
//TC - O(N)
//SC - O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int open = 0, close = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')'){
                if(open){
                    open--;
                }
                else{
                    close++;
                }
            }
            else{
                open++;
            }
        }
        return close + open;
    }
};
