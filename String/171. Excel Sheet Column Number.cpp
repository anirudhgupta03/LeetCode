class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int sum = 0;
        int n = columnTitle.size();
        
        for(int i = n - 1; i >= 0; i--){
            sum += pow(26, n - i - 1)*(columnTitle[i] - 'A' + 1);
        }
        
        return sum;
    }
};
