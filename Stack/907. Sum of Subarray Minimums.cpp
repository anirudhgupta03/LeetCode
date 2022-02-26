//Ref: https://www.youtube.com/watch?v=Ulb3ixSpE4Y
class Solution {
public:
    #define ll long long
    int sumSubarrayMins(vector<int>& arr) {
        
        int mod = 1e9 + 7;
        
        int n = arr.size();
        
        vector<ll> nsl(n);
        
        stack<ll> st;
        st.push(0);
        nsl[0] = -1;        
        
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] >= arr[st.top()]){
                nsl[i] = st.top();
            }
            else{
                while(!st.empty() && arr[i] < arr[st.top()]){
                    st.pop();
                }
                if(st.empty()){
                    nsl[i] = -1;
                }
                else{
                    nsl[i] = st.top();
                }
            }
            st.push(i);
        }
        
        while(st.size()){
            st.pop();
        }
        
        vector<ll> nsr(n);
        
        nsr[n - 1] = n;
        st.push(n - 1);
        
        for(int i = n - 2; i >= 0; i--){
            if(arr[i] > arr[st.top()]){
                nsr[i] = st.top();
            }
            else{
                while(!st.empty() && arr[i] <= arr[st.top()]){
                    st.pop();
                }
                if(st.empty()){
                    nsr[i] = n;
                }
                else{
                    nsr[i] = st.top();
                }
            }
            st.push(i);
        }
        
        ll sum = 0;
        
        for(int i = 0; i < n; i++){
            sum =  (sum + ((arr[i])*(((i - nsl[i])*(nsr[i] - i)))%mod)%mod)%mod;
        }
        return sum;
    }
};
