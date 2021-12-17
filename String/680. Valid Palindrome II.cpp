class Solution {
public:
    bool isPalindrome(string s){
        
        int l = 0,  r = s.size() - 1;
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        
        int l = 0, r = s.size() - 1;
        
        bool flag = true;
        
        while(l < r){
            if(s[l] != s[r]){
                flag = false;
                break;
            }
            l++;
            r--;
        }
        if(flag){
            return true;
        }
        l = 0, r = s.size() - 1;
        
        string s1, s2;
        
        while(l < r){
            
            if(s[l] != s[r]){
                s1 = s.substr(0,l) + s.substr(l + 1, s.size() - l);
                cout << s1 << endl;
                s2 = s.substr(0,r) + s.substr(r + 1, s.size() - r);
                cout << s2 << endl;
                break;
            }
            l++;
            r--;
        }
        
        if(isPalindrome(s1)){
            return true;
        }
        if(isPalindrome(s2)){
            return true;
        }
        return false;
    }
};
