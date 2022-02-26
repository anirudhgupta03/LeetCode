//Method - 1
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int> st;
        int n = s.size();
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(st.empty()){
                    s.erase(s.begin() + i);
                    i--;
                }
                else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            s.erase(s.begin() + st.top());
            st.pop();
        }
        return s;
    }
};

//Method - 2
//Ref: https://www.youtube.com/watch?v=Givpwgu9IIc
//Faster
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int> st;
        int n = s.size();
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(st.empty()){
                    s[i] = '#';
                }
                else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            s[st.top()] = '#';
            st.pop();
        }
        string temp;
        for(int i = 0; i < s.size(); i++){
          if(s[i] != '#'){
             temp.push_back(s[i]);
          }
        }
        return temp;
    }
};
