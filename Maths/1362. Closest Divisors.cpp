class Solution {
public:
    vector<int> closestDivisors(int num) {
        
        int a,b;
        
        int ans = INT_MAX;
        for(int i = 1; i <= sqrt(num) + 1; i++){
            
            int n1 = num/i;
            int n2 = num/i + 1;
            
            if(i*n1 - num == 1 || i*n1 - num == 2){
                if(abs(i-n1) < ans){
                    a= i;
                    b = n1;
                    ans = abs(i-n1);
                }
                continue;
            }
            if(i*n2 - num == 1 || i*n2 - num == 2){
                if(abs(i-n2) < ans){
                    a= i;
                    b = n2;
                    ans = abs(i-n2);
                }
            }
        }
        vector<int> res = {a,b};
        return res;
    }
};
