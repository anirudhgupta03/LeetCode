class TopVotedCandidate {
public:
    vector<int> v;
    vector<int> ttime;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        
        unordered_map<int,pair<int,int>> mp;    //<person,<votes,lastvotetime>>
        int n = persons.size();
        
        v.clear();
        v.resize(n);
        
        ttime = times;
        
        v[0] = persons[0];
        mp[persons[0]] = {1, times[0]};
        
        for(int i = 1; i < n; i++){
            if(mp.find(persons[i]) != mp.end()){
                mp[persons[i]] = {mp[persons[i]].first + 1, times[i]};
            }
            else{
                mp[persons[i]] = {1, times[i]};
            }
            int p = -1, count = -1, t = -1;
            for(auto x: mp){
                if(x.second.first > count){
                    p = x.first;
                    count = x.second.first;
                    t = x.second.second;
                }
                else if(x.second.first == count){
                    if(t < x.second.second){
                        p = x.first;
                        count = x.second.first;
                        t = x.second.second;
                    }
                }
            }
            v[i] = p;
        }
        
    }
    
    int q(int t) {
        
        int lo = 0, hi = ttime.size() - 1;
        int ans;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(ttime[mid] <= t){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        
        return v[ans];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
