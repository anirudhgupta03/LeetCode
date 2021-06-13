//Brute Force Approach
//Time Complexity - O(N*R), where R is the range of [left, right] and N is the number of range in ranges
//Space Complexity - O(1)
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        
        for(int i = left; i <= right; i++){
            
            bool flag = false;
            for(int j = 0; j < ranges.size(); j++){
                
                int l = ranges[j][0], r = ranges[j][1];
                
                if(i >= l && i <= r){
                    flag = true;
                    break;
                }
            }
            
            if(!flag){
                return 0;
            }
        }
        return 1;
    }
};

//Optimal Approach
//Time Complexity - O(N + R)
//Space Complexity - O(1)
//Ref: https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/discuss/1267402/Short-and-Easy-Solution-w-Explanation-or-C%2B%2B-Clean-Code
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        
        int num[52] = {0};
        
        for(int i = 0; i < ranges.size(); i++){
            int l = ranges[i][0], r = ranges[i][1];
            num[l]++;
            num[r+1]--;
        }
        
        for(int i = 1; i < 52; i++){
            num[i] += num[i-1];
        }
        for(int i = left; i <= right; i++){
            
            if(!num[i]){
                return false;
            }
        }
        return true;
    }
};
