//Ref: https://www.youtube.com/watch?v=OB4zw7BqKP8
class Solution {
public:
    #define ll long long
    map<pair<ll,vector<ll>>, bool> dp;
    bool alreadyhappened(vector<ll> &sides, ll pos){
        for(ll i = 0; i < pos; i++){
            if(sides[i] == sides[pos]){
                return true;
            }
        }
        return false;
    }
    bool solve(int ind, ll sum, vector<ll> &v, vector<int> &matchsticks, int tsum){
        
        if(sum == 0 && ind == matchsticks.size()){
            return true;
        }
        if(sum == 0 || ind == matchsticks.size()){
            return false;
        }
        
        for(int i = 0; i < 4; i++){
            if(alreadyhappened(v, i)){
                continue;
            }
            if(v[i] + matchsticks[ind] <= tsum){
                v[i] += matchsticks[ind];
                bool flag = solve(ind + 1, sum - matchsticks[ind], v, matchsticks, tsum);
                if(flag) return true;
                v[i] -= matchsticks[ind];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        
        ll sum = 0;
        
        for(int i = 0; i < matchsticks.size(); i++){
            sum += matchsticks[i];
        }
        
        if(sum % 4 != 0){
            return false;
        }
        
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        
        if(matchsticks[0] > sum/4 || matchsticks.size() < 4){
            return false;
        }
        vector<ll> v(4, 0);
        dp.clear();
        
        return solve(0, sum, v, matchsticks, sum/4);
    }
};
