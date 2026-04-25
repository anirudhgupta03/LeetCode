//Ref: https://www.youtube.com/watch?v=7SBVnw7GSTk
class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();

        int l = 0, r = 0, jumps = 0;

        while(r < n - 1){
            int farthest = 0;
            for(int ind = l; ind <= r; ind++){
                farthest = max(farthest, ind + nums[ind]);
            }
            l = r + 1;
            r = farthest;
            jumps = jumps + 1;
        }
        return jumps;
    }
};
