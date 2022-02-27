//Ref: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/discuss/328841/JavaC%2B%2BPython-O(1)-Extra-Space-Except-Output
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int cnt1 = 0, cnt2 = 0;
        int n = seq.size();
        vector<int> res(n, 0);
        
        for(int i = 0; i < n; i++){
            if(seq[i] == '('){
                if(cnt1 < cnt2) cnt1++;
                else{
                    cnt2++;
                    res[i] = 1;
                }
            }
            else{
                if(cnt1 > cnt2){
                    cnt1--;
                }
                else{
                    cnt2--;
                    res[i] = 1;
                }
            }
        }
        return res;
    }
};
