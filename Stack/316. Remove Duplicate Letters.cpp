//Ref: https://www.youtube.com/watch?v=luCn7p2CIbI
class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        stack<char> st;
        vector<int> freq(26,0), exist(26,0);
        
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            freq[ch - 'a']++; 
        }
        
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            freq[ch - 'a']--;
            
            if(exist[ch - 'a']) continue;
            
            while(st.size() > 0 && st.top() > ch && freq[st.top() - 'a'] > 0){
                exist[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(ch);
            exist[ch - 'a'] = 1;
        }
        
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
