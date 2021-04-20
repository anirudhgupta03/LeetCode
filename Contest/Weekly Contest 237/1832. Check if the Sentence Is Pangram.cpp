class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        int alpha[26] = {0};
        
        for(int i = 0; i < sentence.size(); i++){
            alpha[sentence[i]-97]++;
        }
        
        for(int i = 0; i < 26; i++){
            if(alpha[i] < 1){
                return false;
            }
        }
        return true;
    }
};
