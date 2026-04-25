class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int n = bills.size();

        int fiveDollar = 0, tenDollar = 0, twentyDollar = 0;

        for(int& bill: bills){
            if(bill == 5){
                fiveDollar++;
            }
            else if(bill == 10){
                if(fiveDollar > 0){
                    fiveDollar--;
                    tenDollar++;
                }
                else{
                    return false;
                }
            }
            else if(bill == 20){
                if(fiveDollar >= 1 && tenDollar >= 1){
                    fiveDollar--;
                    tenDollar--;
                    twentyDollar++;
                }
                else if(fiveDollar >= 3){
                    fiveDollar -= 3;
                    twentyDollar++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
