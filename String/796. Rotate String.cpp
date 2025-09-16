class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }
        string str = s;
        str += s;
        for(int i = 0; i < goal.length(); i++){
            if(str.substr(i, goal.length()) == goal){
                return true;
            }
        }
        return false;
    }
};
