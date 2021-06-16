class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int start = newInterval[0], end = newInterval[1];
        
        vector<vector<int>> res;
        
        bool flag = false;
        
        for(int i = 0; i < intervals.size(); i++){
            
            if(intervals[i][1] < start){
                res.push_back(intervals[i]);
            }
            else if(intervals[i][0] > end){
                if(!flag){
                    res.push_back({start,end});
                    flag = true;
                }
                res.push_back(intervals[i]);
            }
            else{
                start = min(start, intervals[i][0]);
                end = max(end,intervals[i][1]);
            }
        }
        if(!flag){
            res.push_back({start,end});
        }
        return res;
    }
};
