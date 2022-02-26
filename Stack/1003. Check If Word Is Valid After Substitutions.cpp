class Solution {
public:
    bool isValid(string s) {
        
        stack<int> st;
        string temp = "abc";
        
        if(s.size() < temp.size()){
            return false;
        }
        
        st.push(0);
        
        int ind = 0;
        
        while(!st.empty()){
            int tind = st.top();
            st.pop();
            
            while(ind < s.size() && tind < temp.size() && temp[tind] == s[ind]){
                ind++;
                tind++;
            }
            
            if(tind != temp.size()){
                st.push(tind);
                if(ind == s.size() || s[ind] != 'a'){
                    return false;
                }
                else{
                    st.push(0);
                }
            }
            else{
                if(!st.empty() && ind == s.size()){
                    return false;
                }
                else if(ind != s.size()){
                    if(s[ind] == 'a'){
                        st.push(0);
                    }
                }
            }
        }
        if(ind == s.size()) return true;
        return false;
    }
};
