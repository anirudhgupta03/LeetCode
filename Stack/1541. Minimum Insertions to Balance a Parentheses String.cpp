class Solution {
public:
    int minInsertions(string s) {
        
        stack<char> st;
        
        int count = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '('){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    if(i < s.size() - 1){
                        if(s[i + 1] == ')'){
                            i++;
                            count++;
                        }
                        else{
                            count += 2;
                        }
                    }
                    else{
                        count += 2;
                    }
                }
                else{
                    if(i < s.size() - 1){
                        if(s[i + 1] == ')'){
                            i++;
                            st.pop();
                        }
                        else{
                            count++;
                            st.pop();
                        }
                    }
                    else{
                        count++;
                        st.pop();
                    }
                }
            }
        }
        return count + 2*st.size();
    }
};
