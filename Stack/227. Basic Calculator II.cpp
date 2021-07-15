//Ref: https://www.youtube.com/watch?v=gmy6L9vHTbo
class Solution {
public:
    int calculate(string s) {
        
        stack<int> st;
        int n = s.size();
        char sign = '+';
        for(int i = 0; i < n; i++){
            
            char ch = s[i];
            
            if(isdigit(ch)){
                int val = 0;
                
                while(i < n && isdigit(s[i])){
                    val = 10*val - '0' + s[i];
                    i++;
                }
                i--;
                if(sign == '+'){
                    st.push(val);
                }
                else if(sign == '-'){
                    st.push(-val);
                }
                else if(sign == '*'){
                    int a = st.top();
                    st.pop();
                    int ans = a*val;
                    st.push(ans);
                }
                else{
                    int a = st.top();
                    st.pop();
                    int ans = a/val;
                    st.push(ans);
                }
            }
            else if(ch != ' '){
                sign = ch;
            }
        }
        
        int sum = 0;
        while(st.size()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
