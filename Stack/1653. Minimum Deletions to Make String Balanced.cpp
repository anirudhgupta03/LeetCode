//Ref: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/discuss/935701/DP-solution-beats-100-with-explanation
class Solution {
public:
    int minimumDeletions(string s) {
        
        int cnt = 0, b = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a'){
                cnt = min(b, cnt + 1);
            }
            else{
                b++;
            }
        }
        return cnt;
    }
};
