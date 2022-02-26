//Ref: https://www.youtube.com/watch?v=dsusgzffTDA
class Solution {
public:
    #define pii pair<int,int>
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        
        vector<int> res(n, 0);
        
        stack<pii> st;
        
        for(int i = 0; i < logs.size(); i++){
            string s = logs[i];
            int itr = 0;
            int id = 0, start = 0;
            while(itr < s.size() && s[itr] != ':'){
                id = 10*id + (s[itr] - '0');
                itr++;
            }
            itr++;
            if(s[itr] == 's'){
                int start = 0;
                while(itr < s.size() && s[itr] != ':') itr++;
                itr++;
                while(itr < s.size()){
                    start = 10*start + (s[itr] - '0');
                    itr++;
                }
                st.push({start, 0});
            }
            else{
                int stt = st.top().first, ct = st.top().second;
                st.pop();
                
                int edt = 0;
                while(itr < s.size() && s[itr] != ':') itr++;
                itr++;
                while(itr < s.size()){
                    edt = 10*edt + (s[itr] - '0');
                    itr++;
                }
            
                int interval = (edt - stt + 1) - ct;
                res[id] += interval;
                
                if(!st.empty()){
                    st.top().second += edt - stt + 1;
                }
            }
        }
        return res;
    }
};
