class Solution {
public:
    #define ll long long
    bool isHappy(int n) {
        
        unordered_set<ll> us;
        
        while(n != 1){
            if(us.find(n) != us.end()){
                return false;
            }
            else{
                us.insert(n);
            }
            ll sum = 0;
            
            while(n){
                sum += (n % 10)*(n % 10);
                n /= 10;
            }
            n = sum;
        }
        return true;
    }
};
