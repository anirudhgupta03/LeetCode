class Solution {
public:
    int reverse(int x) {
        
        long sum = 0;
        
        int temp = x;
        
        while(temp){
            sum = 10*sum + temp%10;
            temp /= 10;
        }
    
        if(sum < INT_MIN || sum > INT_MAX){
                return 0;
        }
        return sum;
    }
};
