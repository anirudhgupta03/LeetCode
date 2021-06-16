//Time Complexity - O(N)
//Space Complexity - O(1)
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int start = timeSeries[0], end = timeSeries[0] + duration - 1;
        
        int totalTime = 0;
        
        for(int i = 1; i < timeSeries.size(); i++){
            
            if(timeSeries[i] <= end){
                end = max(end,timeSeries[i] + duration - 1);
            }
            else{
                totalTime += end - start + 1;
                start = timeSeries[i];
                end = timeSeries[i] + duration - 1;
            }
        }
        
        totalTime += end - start + 1;
        return totalTime;
    }
};
