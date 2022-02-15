class Solution {
public:
    bool isValidSerialization(string s) {
        
        if(s[0] == ','){
            return false;
        }
        if(s[0] == '#'){
            if(s.size() == 1){
                return true;
            }
            return false;
        }
        s.push_back(',');
        stack<string> st;
        string temp = "";
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ','){
                st.push(temp);
                while(st.size() > 2){
                    string s1 = st.top();
                    st.pop();
                    string s2 = st.top();
                    st.pop();
                    string s3 = st.top();
                    st.pop();
                    if(s1 == "#" && s2 == "#" && s3 == "#"){
                        return false;
                    }
                    if(s1 == "#" && s2 == "#" && s3 != "#"){
                        st.push("#");
                    }
                    else{
                        st.push(s3);
                        st.push(s2);
                        st.push(s1);
                        break;
                    }
                }
                temp.clear();
            }
            else{
                temp.push_back(s[i]);
            }
        }
        return st.size() == 1 && st.top() == "#";
    }
};
