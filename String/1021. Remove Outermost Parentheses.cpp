class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int sum = 0;

        for(char &ch: s){
            if(ch == '('){
                sum++;
                if(sum != 1){
                    res.push_back('(');
                }
            }
            else if(ch == ')'){
                sum--;
                if(sum != 0){
                    res.push_back(')');
                }
            }
        }
        return res;
    }
};
