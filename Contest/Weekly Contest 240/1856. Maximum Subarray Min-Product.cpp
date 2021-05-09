class Solution {
public:
    #define pii pair<int,int>
    #define ll long long
  
    int maxSumMinProduct(vector<int>& nums) {
        
        int n = nums.size();
        
        int mod = 1000000007;
        
        ll sum[n+1];
        
        sum[0] = 0;
        
        for(int i = 1; i <= n; i++){
            sum[i] = sum[i-1] + nums[i-1];
        }
        
        vector<int> nsl(n);
        vector<int> nsr(n);
        
        priority_queue<pii> pq;
        
        //Evaluate Nearest Smaller to Left
        nsl[0] = -1;
        
        pq.push({nums[0],0});
        
        for(int i = 1; i < nums.size(); i++){
            
            if(pq.top().first < nums[i]){
                nsl[i] = pq.top().second;
            }
            else{
                
                while(!pq.empty() && pq.top().first >= nums[i]){
                    pq.pop();
                }
                
                if(pq.empty()){
                    nsl[i] = -1;
                }
                else{
                    nsl[i] = pq.top().second;
                }
            }
            
            pq.push({nums[i],i});
        }
        
        while(pq.size()){
            pq.pop();
        }
        
        //Evaluate Nearest Smaller to right
        nsr[n-1] = -1;
        pq.push({nums[n-1],n-1});
        
        for(int i = n - 2; i >= 0; i--){
            
            if(pq.top().first < nums[i]){
                nsr[i] = pq.top().second;
            }
            else{
                
                while(!pq.empty() && pq.top().first >= nums[i]){
                    pq.pop();
                }
                
                if(pq.empty()){
                    nsr[i] = -1;
                }
                else{
                    nsr[i] = pq.top().second;
                }
            }
            pq.push({nums[i],i});
        }
        
        ll ans = 0;
        
        for(int i = 0; i < n; i++){
            
            int l = nsl[i], r = nsr[i];
            
            if(r == -1) r = n;
            
            if((ll)(nums[i]) * (sum[r]-sum[l+1]) > ans)
                ans = nums[i]*(sum[r]-sum[l+1]);
        }
        return ans % mod;
    }
};
