//Method - 1
//Greedy Approach
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        int count = 0;
    
        int end = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); i++){
            if(end > intervals[i][0]){
                count++;
                end = min(end,intervals[i][1]);
            }
            else{
                end = intervals[i][1];
            }
        }
        return count;
    }
};

//Method - 2
class Solution {
public:
    bool static cmp(vector<int> &v1, vector<int> &v2){
        return v1[1] < v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        int count = 0, e = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); i++){
            
            if(intervals[i][0] >= e){
                e = intervals[i][1];
            }
            else{
                count++;
            }
        }
        return count;
    }
};
