class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        int start = intervals[0][0], end = intervals[0][1];
        
        vector<vector<int>> res;
        
        for(int i = 1; i < intervals.size(); i++){
            
            if(end >= intervals[i][0]){
                end = max(end,intervals[i][1]);
            }
            else{
                vector<int> temp = {start,end};
                start = intervals[i][0];
                end = intervals[i][1];
                res.push_back(temp);
            }
        }
        vector<int> temp = {start,end};
        res.push_back(temp);
        return res;
    }
};
