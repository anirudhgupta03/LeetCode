class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1;
        int t;
        
        for(int i = digits.size() - 1; i >= 0; i--){
            t = digits[i] + carry;
            digits[i] = t%10;
            carry = t/10;
        }
        
        if(carry != 0){
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};
