class Solution {
public:
    #define ll long long
    bool isPossible(ll side, ll neededApples, vector<ll> &v){
        if(v[side - 1] >= neededApples){
            return true;
        }
        return false;
    }
    long long minimumPerimeter(long long neededApples) {
        
        vector<ll> v;
        ll sum = 0, length = 0;
        
        while(sum <= 1e15){
            length++;
            sum += 12*(length*length);
            v.push_back(sum);
        }
        
        ll lo = 1, hi = v.size(), ans;
        
      while(lo <= hi){
            ll mid = (lo + hi)/2;
            if(isPossible(mid, neededApples, v)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return 8*ans;
    }
};
