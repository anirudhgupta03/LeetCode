class Solution {
public:
    int countPrimes(int n) {
        
        if(n <= 2){
            return 0;
        }
        int sieve[n], count = 0;
        memset(sieve,0,sizeof(sieve));
        
        for(int i = 2; i * i < n; i++){
            if(sieve[i] == 0){
                for(int p = i*i; p < n; p += i){
                    sieve[p] = 1;
                }
            }
        }
        
        for(int i = 2; i < n; i++){
            if(sieve[i] == 0){
                count++;
            }
        }
        return count;
    }
};
