//Ref: https://leetcode.com/problems/time-based-key-value-store/discuss/226664/C++-3-lines-hash-map-+-map/227788
class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> mp; 
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        
        int lo = 0, hi = mp[key].size() - 1, ans = -1;
        
        while(lo <= hi){
            
            int mid = lo + (hi - lo)/2;
            
            if(mp[key][mid].second <= timestamp){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        if(ans == -1) return "";
        return mp[key][ans].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
