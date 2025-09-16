//Method - 1
class Solution {
public:
    string reverseWords(string s) {

        int len = s.length();
        string res;

        int i = 0;

        while(i < len){
            while(i < len && s[i] == ' ') i++;
            string temp;
            while(i < len && s[i] != ' '){
                temp.push_back(s[i]);
                i++;
            }
            if(temp.length() > 0){
                res = temp + " " + res;
            }
        }
        if(res.length() > 0){
            res.pop_back();
        }
        return res;
    }
};
