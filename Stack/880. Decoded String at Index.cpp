//Ref: https://www.youtube.com/watch?v=p-GPuy01a7A
class Solution {
public:
    #define ll long long
    string decodeAtIndex(string s, int k) {
        
        ll size = 0;
        
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            
            if(isdigit(ch)){
                size *= (ch - '0');
            }
            else{
                size++;
            }
        }
        
        string res;
        for(int i = s.size() - 1; i >= 0; i--){
            char ch = s[i];
            k = k % size;
            
            if(k == 0 && !isdigit(ch)){
                res = ch;
                break;
            }
            if(isdigit(ch)){
                size = size/(ch - '0');
            }
            else{
                size--;
            }
        }
        return res;
    }
};
