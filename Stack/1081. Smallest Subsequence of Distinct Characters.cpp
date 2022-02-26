class Solution {
public:
    string smallestSubsequence(string s) {
        
        vector<int> alpha(26,0);
        
        for(int i = 0; i < s.size(); i++){
            alpha[s[i] - 'a']++;
        }
        
        stack<char> st;
        st.push(s[0]);
      
        vector<int> vis(26, 0);
        vis[s[0] - 'a'] = 1;
        alpha[s[0] - 'a']--;
      
        for(int i = 1; i < s.size(); i++){
            alpha[s[i]- 'a']--;
            if(vis[s[i] - 'a']) continue;
            while(!st.empty() && s[i] < st.top() && alpha[st.top() - 'a']){
                vis[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i] - 'a'] = 1;
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
