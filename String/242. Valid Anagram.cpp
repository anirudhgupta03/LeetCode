//Method - 1
//Time Complexity - O(N)
//Space Complexity - O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int> alpha1(26,0);
        vector<int> alpha2(26,0);
        
        if(s.size() != t.size()){
            return false;
        }
        
        for(int i = 0; i < s.size(); i++){
            alpha1[s[i]-'a']++;
            alpha2[t[i]-'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if(alpha1[i] != alpha2[i]){
                return false;
            }
        }
        return true;
    }
};

//Method - 2
// Runtime: 4 ms, faster than 99.05% of C++ online submissions for Valid Anagram.
// Memory Usage: 7.4 MB, less than 29.46% of C++ online submissions for Valid Anagram.
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int> alpha(26,0);
        
        if(s.size() != t.size()){
            return false;
        }
        
        for(int i = 0; i < s.size(); i++){
            alpha[s[i]-'a']++;
        }
        
        for(int i = 0; i < t.size(); i++){
            alpha[t[i]-'a']--;
        }
        
        for(int i = 0; i < 26; i++){
            if(alpha[i] != 0){
                return false;
            }
        }
        return true;
    }
};

//Method - 3
// Runtime: 8 ms, faster than 86.32% of C++ online submissions for Valid Anagram.
// Memory Usage: 7.2 MB, less than 88.70% of C++ online submissions for Valid Anagram.
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int> alpha(26,0);
        
        if(s.size() != t.size()){
            return false;
        }
        
        for(int i = 0; i < s.size(); i++){
            alpha[s[i]-'a']++;
            alpha[t[i]-'a']--;
        }
        
        for(int i = 0; i < 26; i++){
            if(alpha[i] != 0){
                return false;
            }
        }
        return true;
    }
};

//Method - 4
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int> alpha(26,0);
        
        if(s.size() != t.size()){
            return false;
        }
        
        for(int i = 0; i < s.size(); i++){
            alpha[s[i]-'a']++;
            //alpha[t[i]-'a']--;
        }
        
        for(int i = 0; i < t.size(); i++){
            alpha[t[i]-'a']--;
            if(alpha[t[i]-'a'] < 0){
                return false;
            }
        }
        return true;
    }
};
