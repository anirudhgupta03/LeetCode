class Solution {
public:
    bool isPalindrome(string s) {
        
        string temp;
        
        for(int i = 0; i < s.size(); i++){
            
            if(isalpha(s[i])){
                temp.push_back(tolower(s[i]));
            }
            else if(isdigit(s[i])){
                temp.push_back(s[i]);
            }
        }
        
        int lo = 0, hi = temp.size() - 1;
        
        while(lo < hi){
            if(temp[lo] != temp[hi]){
                return false;
            }
            lo++;hi--;
        }
        
        return true;
    }
};
