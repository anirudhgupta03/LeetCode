//Method - 1
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

//Method - 2
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        vector<vector<int>> temp = intervals;
        
        for(int i = 0; i < temp.size(); i++){
            temp[i].push_back(i);
        }
        sort(temp.begin(), temp.end());
        
        vector<int> res;
        
        for(int i = 0; i < intervals.size(); i++){
            
            int lo = 0, hi = temp.size() - 1, endi = intervals[i][1], ans = -1;
            
            while(lo <= hi){
                
                int mid = lo + (hi - lo)/2;
                
                if(temp[mid][0] >= endi){
                    ans = temp[mid][2];
                    hi = mid - 1;
                } 
                else{
                    lo = mid + 1;
                }
            }
            
            res.push_back(ans);
        }
        return res;
    }
};
