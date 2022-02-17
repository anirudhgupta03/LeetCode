//Ref: https://www.youtube.com/watch?v=RCE2L0Zk7xE
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char> st;
        
        for(int i = 0; i < num.size(); i++){
            char ch = num[i];
            while(!st.empty() && st.top() > ch && k){
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while(!st.empty() && k){
            st.pop();
            k--;
        }
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        int i = 0;
        while(i < res.size()){
            if(res[i] == '0') i++;
            else break;
        }
        if(i == res.size()){
            return "0";
        }
        return res.substr(i);
    }
};
