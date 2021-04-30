class Solution {
public:
    #define ll long long
    #define pll pair<long,long>
    
    void buyorder(int price, int amt, priority_queue<pll> &buy, priority_queue<pll,vector<pll>,greater<pll>> &sell){
        
                if(sell.empty()){
                    
                    buy.push({price,amt});
                }
                else if(sell.top().first <= price){

            
                    ll amt1 = sell.top().second;
                    
                    while(!sell.empty() && sell.top().first <= price){
                        
                        if(amt >= amt1){
                            amt -= amt1;
                            amt1 = 0;
                        }
                        else{
                            amt1 -= amt;
                            amt = 0;
                        }
                        
                        if(amt1 == 0){
                            sell.pop();
                            if(!sell.empty()){
                                amt1 = sell.top().second;
                            }
                        }
                        if(amt == 0) break;
                    }
                    
                    if(amt1 != 0){
                        int p = sell.top().first;
                        sell.pop();
                        sell.push({p,amt1});
                    }
                    if(amt != 0){
                        buy.push({price,amt});
                    }
                }
                else{
                    buy.push({price,amt});
                }
    }
    void sellorder(int price, int amt, priority_queue<pll> &buy, priority_queue<pll,vector<pll>,greater<pll>> &sell){
        
                if(buy.empty()){
                    sell.push({price,amt});
                }
                else if(buy.top().first >= price){
                    
                    ll amt1 = buy.top().second;
                    
                    while(!buy.empty() && buy.top().first >= price){
                        
                        if(amt >= amt1){
                            amt -= amt1;
                            amt1 = 0;
                        }
                        else{
                            amt1 -= amt;
                            amt = 0;
                        }
                        
                        if(amt1 == 0){
                            buy.pop();
                            if(!buy.empty()){
                                amt1 = buy.top().second;
                            }
                            else{
                                break;
                            }
                        }
                        if(amt == 0) break;
                    }
                    
                    if(amt1 != 0){
                        int p = buy.top().first;
                        buy.pop();
                        buy.push({p,amt1});
                    }
                    if(amt != 0){
                        sell.push({price,amt});
                    }
                }
                else{
                    sell.push({price,amt});
                }
    }
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        
        priority_queue<pll> buy;
        priority_queue<pll,vector<pll>,greater<pll>> sell;
        
        for(int i = 0; i < orders.size(); i++){
            
            int price = orders[i][0], amt = orders[i][1], type = orders[i][2];
            
            if(type == 0){
                buyorder(price,amt,buy,sell);
            }
            else{
                sellorder(price,amt,buy,sell);
            }
        }
        
        ll count1 = 0, count2 = 0;
        
        while(buy.size()){
            count1 = (count1 + buy.top().second);
            buy.pop();
        }

        while(sell.size()){
            count2 =  (count2 + sell.top().second);
            sell.pop();
        }
        return (count1 + count2) %(1000000007);
    }
};
