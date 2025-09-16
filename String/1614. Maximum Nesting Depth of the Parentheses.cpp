class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, ans = 0;
        for(char &ch: s){
            if(ch == '('){
                depth++;
            }
            else if(ch == ')'){
                depth--;
            }
            ans = max(ans, depth);
        }
        return ans;
    }
};
