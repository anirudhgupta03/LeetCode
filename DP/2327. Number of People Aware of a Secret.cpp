class Solution {
public:
    #define mod 1000000007
    #define ll long long
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        vector<ll> v(n + 1);
        
        if(n <= delay){
            return 1;
        }
        
        vector<ll> temp(forget + 2, 0);
        
        temp[1] = 1;
        v[1] = 1;
        
        ll sum = 0;
        for(int i = 2; i <= n; i++){
            vector<ll> ttemp(forget + 2, 0);
            
            for(int j = 1; j <= forget; j++){
                ttemp[j + 1] = temp[j];
            }
            for(int j = delay + 1; j <= forget; j++){
                ttemp[1] = (ttemp[1] + ttemp[j]) % mod;
            }
            
            sum = 0;
            for(int j = 1; j <= 1 + forget; j++){
                sum = (sum + ttemp[j])%mod;
            }
            ttemp[forget + 1] = 0;
            temp = ttemp;
        }
        sum = 0;
        for(int j = 1; j <= forget; j++){
            sum = (sum + temp[j])%mod;
        }
        return sum % mod;
    }
};
