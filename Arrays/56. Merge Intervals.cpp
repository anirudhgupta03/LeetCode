//Sort the vector first
//then we check that if the second value of a particular vector if lesser or equal
//then accordingly we add


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        
        if(intervals.size()==0){
            return mergedIntervals;
        }
        
        sort(intervals.begin(),intervals.end());
        vector<int> tempInterval = intervals[0];
        
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]<=tempInterval[1]){
                tempInterval[1]=max(intervals[i][1],tempInterval[1]);
            }
            else{
                mergedIntervals.push_back(tempInterval);
                tempInterval=intervals[i];
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
};
