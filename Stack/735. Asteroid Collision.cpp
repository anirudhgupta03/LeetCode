class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        
        st.push(asteroids[0]);
        
        for(int i = 1; i < asteroids.size(); i++){
            
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            }
            else{
                while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])){
                    st.pop();
                }
                
                if(st.empty()){
                    st.push(asteroids[i]);
                }
                else{
                    if(st.top() == abs(asteroids[i])){
                        st.pop();
                    }
                    else if(st.top() < 0){
                        st.push(asteroids[i]);
                    }
                }
            }
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
