//Method - 1
class Solution {
public:
    #define ll long long
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        
        ll n = tiles.size();
        
        sort(tiles.begin(), tiles.end());
        
        vector<ll> count(n);
        
        for(ll i = 0; i < n; i++){
            count[i] = tiles[i][1] - tiles[i][0] + 1;
        }
        
        vector<ll> prefix(n + 1);
        prefix[0] = 0;
        
        for(ll i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + count[i - 1];
        }
        
        ll ans = 0;
        
        for(ll i = 0; i < n; i++){
            
            ll temp1 = tiles[i][0] + carpetLen - 1; //10
            ll temp2 = tiles[i][1] + carpetLen - 1; //14
            
            ll lo = i, hi = n - 1;
            ll tiles1 = 0;
            ll tiles2 = 1;
            
            ll ind = i;
            
            while(lo <= hi){
                ll mid = (lo + hi)/2;
                if(temp1 < tiles[mid][0]){
                    hi = mid - 1;
                }
                else if(temp1 > tiles[mid][1]){
                    ind = mid;
                    lo = mid + 1;
                }
                else{
                    ind = mid;
                    break;
                }
            }
            
            if(temp1 > tiles[ind][1]){
                tiles1 += prefix[ind + 1] - prefix[i];
            }
            else{
                tiles1 += prefix[ind] - prefix[i] + temp1 - tiles[ind][0] + 1;
            }
            
            lo = i + 1, hi = n - 1;
            
            ind = i;
            
            while(lo <= hi){
                ll mid = (lo + hi)/2;
                if(temp2 < tiles[mid][0]){
                    hi = mid - 1;
                }
                else if(temp2 > tiles[mid][1]){
                    ind = mid;
                    lo = mid + 1;
                }
                else{
                    ind = mid;
                    break;
                }
            }

            if(temp2 > tiles[ind][1]){
                if(ind != i) tiles2 += prefix[ind + 1] - prefix[i + 1];
            }
            else{
                tiles2 += prefix[ind] - prefix[i + 1] + temp2 - tiles[ind][0] + 1;
            }
            // cout << tiles1 << " " << tiles2 << endl;
            ans = max(ans, max(tiles1, tiles2));
        }
        return ans;
    }
};

//Method - 2
//Checking from front end will be sufficient
class Solution {
public:
    #define ll long long
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        
        ll n = tiles.size();
        
        sort(tiles.begin(), tiles.end());
        
        vector<ll> count(n);
        
        for(ll i = 0; i < n; i++){
            count[i] = tiles[i][1] - tiles[i][0] + 1;
        }
        
        vector<ll> prefix(n + 1);
        prefix[0] = 0;
        
        for(ll i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + count[i - 1];
        }
        
        ll ans = 0;
        
        for(ll i = 0; i < n; i++){
          
            ll temp = tiles[i][0] + carpetLen - 1;
            ll lo = i, hi = n - 1;
            ll ctiles = 0;
            
            ll ind = i;
            
            while(lo <= hi){
                ll mid = (lo + hi)/2;
                if(temp < tiles[mid][0]){
                    hi = mid - 1;
                }
                else if(temp > tiles[mid][1]){
                    ind = mid;
                    lo = mid + 1;
                }
                else{
                    ind = mid;
                    break;
                }
            }
            
            if(temp > tiles[ind][1]){
                ctiles += prefix[ind + 1] - prefix[i];
            }
            else{
                ctiles += prefix[ind] - prefix[i] + temp - tiles[ind][0] + 1;
            }
            ans = max(ans, ctiles);
        }
        return ans;
    }
};
