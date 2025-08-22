//Ref: https://www.youtube.com/watch?v=Ae_Ag_saG9s
class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        vector<int> divisors;
        divisors.push_back(1);
        if(n != 1){
            divisors.push_back(n);
        }
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){
                divisors.push_back(i);
                if(n/i != i){
                    divisors.push_back(n/i);
                }
            }
        }
        sort(divisors.begin(), divisors.end());
        for(int i: divisors){
            cout << i << " ";
        }
    }
};
