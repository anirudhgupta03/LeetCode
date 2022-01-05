class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        
        for(int i = 0; i < n; i++){
            intervals[i].push_back(i);
        }
        
        sort(intervals.begin(), intervals.end());
        
        vector<pair<int,int>> start(n);
        vector<pair<int,int>> end(n);
        
        for(int i = 0; i < n; i++){
            start[i] = {intervals[i][0],intervals[i][2]};
            end[i] = {intervals[i][1],intervals[i][2]};
        }
        
        vector<int> res(n,-1);
        
        for(int i = 0; i < n; i++){
            
            int lo = 0, hi = n - 1;
            int ind = -1;
            
            while(lo <= hi){
                int mid = (lo + hi)/2;
                if(start[mid].first >= end[i].first){
                    ind = start[mid].second;
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }
            
            res[end[i].second] = ind;
        }
        return res;
    }
};
