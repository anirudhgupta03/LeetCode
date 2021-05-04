//Ref: https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/discuss/1118806/Short-and-Easy-w-Explanation-or-Greedy-Approach
//Tricky Question
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        
        sort(coins.begin(),coins.end());
        
        int maxsum = 1;
        
        for(int i = 0; i < coins.size(); i++){
            
            if(maxsum >= coins[i]){
                maxsum += coins[i];
            }
            else{
                break;
            }
        }
        
        return maxsum;
    }
};
