class Solution {
public:
    bool static cmp(vector<int> v1, vector<int> v2){
        if(v1[0] == v2[0]){
            return v1[1] > v2[1];
        }
        return v1[0] < v2[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int end = intervals[0][1];
        
        int count = 1;
        
        for(int i = 1; i < intervals.size(); i++){
            if(!(intervals[i][1] <= end)){
                count++;
                end = intervals[i][1];
            }
        }
        return count;
    }
};
