class Solution {
public:
    #define ll long long
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        ll minSum = INT_MAX, maxSum = INT_MIN;
        
        ll sum = 0;
        
        for(auto &x: differences){
            sum += x;
            maxSum = max(maxSum, sum);
            minSum = min(minSum, sum);
        }
        
        int count = 0;
        
        for(ll i = lower; i <= upper; i++){
            
            if(i + maxSum <= upper && i + minSum >= lower){
                count++;
            }
        }
        return count;
    }
};
