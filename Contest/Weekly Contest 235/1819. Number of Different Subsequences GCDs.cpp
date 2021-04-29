//Ref1: https://www.youtube.com/watch?v=ZYJDCcKnwag
//Ref2: https://leetcode.com/problems/number-of-different-subsequences-gcds/discuss/1142765/C%2B%2B-Detailed-Explanation-or-Easy-to-understand-or-O(M*log(M))
class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        
        int mx = *max_element(nums.begin(),nums.end());
        
        vector<int> vis(mx+1,0);
        
        for(int i = 0; i < nums.size(); i++){
            vis[nums[i]] = 1;
        }
        
        int count = 0;
        
        for(int i = 1; i <= mx; i++){
            
            int g = 0;
            for(int j = i; j <= mx; j += i){
                
                if(vis[j]){
                    g = __gcd(j,g);
                }
            }
            
            if(g == i){
                count++;
            }
        }
        
        return count;
    }
};
