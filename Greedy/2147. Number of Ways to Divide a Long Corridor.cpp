//Ref: https://www.youtube.com/watch?v=WrcIka-QnZc
class Solution {
public:
    #define ll long long
    int numberOfWays(string corridor) {
        
        ll count = 0;
        
        for(int i = 0; i < corridor.size(); i++){
            if(corridor[i] == 'S') count++;
        }
        
        if(count == 0 || count  % 2 != 0){
            return 0;
        }
        
        ll temp = 0, ans = 1;
        int mod = 1e9 + 7;
        
        int i = 0;
        
        while(i < corridor.size()){
            
            if(corridor[i] == 'S') temp++;
            if(temp == 2){
                int cnt = 1;
                i++;
                while(i < corridor.size() && corridor[i] == 'P'){
                    cnt++;
                    i++;
                }
                if(i == corridor.size()) break;
                ans = (ans*cnt)%mod;
                temp = 0;
            }else{
                i++;
            }
        }
        return ans;
    }
};
