class Solution {
public:
    #define ll long long
    int maxProfit(vector<int>& inventory, int orders) {
        
        inventory.push_back(0);
        
        sort(inventory.begin(), inventory.end());
        
        ll n = inventory.size();
        
        ll sum = 0, count = 1;
        
        int mod = 1e9 + 7;
        
        for(ll i = n - 1; i >= 1; i--){
            
            ll start = inventory[i-1] + 1, end = inventory[i];
            
            ll totalelements = (end - start + 1)*(count);
            
            if(orders <= totalelements){
                ll temp = orders/count;
                
                ll temp1 = ((end*(end + 1))/2 - ((end - temp)*(end - temp + 1))/2)*(count);
                ll temp2 = 0;
                
                if(orders %count != 0){
                    temp2 = (end - temp)*(orders - temp*count);
                }
                
                sum = (sum + temp1 + temp2)%mod;
                break;
            }
            else{
                ll temp1 = (end*(end + 1))/2;
                ll temp2 = (start*(start - 1))/2;
                
                sum = (sum + (temp1 - temp2)*count)%mod;
                orders -= totalelements;
            }
            count++;
        }
        return sum;
    }
};
