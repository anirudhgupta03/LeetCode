class Solution {
public:
    int valueOfRomanCharacter(char ch){
        switch(ch){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            default: return 1000;
        }
        return -1;
    }
    int romanToInt(string s) {
        int sum = 0;
        for(int i = 0; i < s.length() - 1; i++){
            if(valueOfRomanCharacter(s[i]) < valueOfRomanCharacter(s[i + 1])){
                sum -= valueOfRomanCharacter(s[i]);
            }
            else{
                sum += valueOfRomanCharacter(s[i]);
            }
        }
        sum += valueOfRomanCharacter(s[s.length() - 1]);
        return sum;
    }
};
