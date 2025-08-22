//Method - 1
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

//Method - 2
class Solution {
public:
    bool isAlphaNumeric(char ch){
        if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9'){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int lo = 0, hi = s.length() - 1;
        while(lo < hi){
            while(lo < hi && !isAlphaNumeric(s[lo])) lo++;
            while(lo < hi && !isAlphaNumeric(s[hi])) hi--;
            if(lo < hi){
                if(tolower(s[lo]) != tolower(s[hi])){
                    return false;
                }
                lo++;
                hi--;
            }
        }
        return true;
    }
};
