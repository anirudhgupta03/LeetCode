class Solution {
public:
    #define ll long long
    #define pll pair<long,long>
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        
        int mod = 1e9 + 7;
        
        priority_queue<pll> buy;    //max-heap
        priority_queue<pll,vector<pll>,greater<pll>> sell; //min-heap
        
        for(int i = 0; i < orders.size(); i++){
            
            ll oprice = orders[i][0], oamt = orders[i][1], otype = orders[i][2];
            
            if(otype == 0){
                
                if(sell.empty() || sell.top().first > oprice){
                    buy.push({oprice,oamt});
                }
                else{
                    ll x = sell.top().first, y = sell.top().second;
                    
                    while(!sell.empty() && x <= oprice){
                        
                        if(oamt >= y){
                            oamt -= y;
                            sell.pop();
                            if(!sell.empty()){
                                x = sell.top().first;
                                y = sell.top().second;
                            }
                        }
                        else{
                            y -= oamt;
                            sell.pop();
                            sell.push({x,y});
                            oamt = 0;
                            break;
                        }
                    }
                    if(oamt != 0){
                        buy.push({oprice,oamt});
                    }
                }
            }
            else{
                
                if(buy.empty() || buy.top().first < oprice){
                    sell.push({oprice,oamt});
                }
                else{
                    ll x = buy.top().first, y = buy.top().second;
                    
                    while(!buy.empty() && x >= oprice){
                        
                        if(oamt >= y){
                            oamt -= y;
                            buy.pop();
                            if(!buy.empty()){
                                x = buy.top().first;
                                y = buy.top().second;
                            }
                        }
                        else{
                            y -= oamt;
                            buy.pop();
                            buy.push({x,y});
                            oamt = 0;
                            break;
                        }
                    }
                    
                    if(oamt != 0){
                        sell.push({oprice,oamt});
                    }
                    
                }
            }
        }
        
        ll backlog = 0;
        
        while(!buy.empty()){
            backlog += buy.top().second;
            buy.pop();
        }
        while(!sell.empty()){
            backlog += sell.top().second;
            sell.pop();
        }
        return backlog%mod;
    }
};
