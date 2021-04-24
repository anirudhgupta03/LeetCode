class Solution {
public:
    string simplifyPath(string path) {
        
        string s1 = ".", s2 = "..";
        
        stack<string> st;
        
        for(int i = 0; i < path.size(); i++){
            
            if(path[i] == '/') 
                continue;
            string s;
            
            while(i < path.size() && path[i] != '/'){
                s.push_back(path[i]);
                i++;
            }
            
            if(s == s1){
                continue;
            }
            else if(s == s2){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s);
            }
        }
        
        if(st.empty()){
            return "/";
        }
        
        string ans;
        
        while(st.size()){
            
            string temp = st.top();
            st.pop();
            reverse(temp.begin(),temp.end());
            temp.push_back('/');
            
            ans += temp;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
