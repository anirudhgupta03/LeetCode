class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<char> character;
        stack<int> index;
        
        index.push(-1);
        
        int maxLen = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '('){
                character.push('(');
                index.push(i);
            }
            else{
                if(character.empty()){
                    index.push(i);
                }
                else{
                    character.pop();
                    index.pop();
                    maxLen = max(maxLen,i - index.top());
                }
            }
        }
        
        return maxLen;
    }
};
