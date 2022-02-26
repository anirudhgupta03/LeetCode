class Solution {
public:
    #define pci pair<char,int>
    string removeDuplicates(string s, int k) {
        stack<pci> st;
        
        for(int i = 0; i < s.size(); i++){
            if(st.empty()){
                st.push({s[i], 1});
            }
            else if(s[i] == st.top().first){
                if(st.top().second + 1 == k){
                    int temp = k - 1;
                    while(temp--){
                        st.pop();
                    }
                }
                else{
                    st.push({s[i], st.top().second + 1});
                }
            }
            else{
                st.push({s[i],1});
            }
        }
        string res;
        while(!st.empty()){
            res.push_back(st.top().first);
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
