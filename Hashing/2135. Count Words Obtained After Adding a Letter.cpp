class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        
        map<vector<int>,int> mp;
        
        for(int i = 0; i < startWords.size(); i++){
            vector<int> alpha(26,0);
            
            for(int j = 0; j < startWords[i].size(); j++){
                alpha[startWords[i][j] - 'a']++;
            }
            
            mp[alpha]++;
        }
        
        int count = 0;
        
        for(int i = 0; i < targetWords.size(); i++){
            
            vector<int> alpha(26,0);
            for(int j = 0; j < targetWords[i].size(); j++){
                alpha[targetWords[i][j] - 'a']++;
            }
            
            for(int k = 0; k < 26; k++){
                if(alpha[k] == 1){
                    alpha[k] = 0;
                    if(mp.find(alpha) != mp.end()){
                        cout << targetWords[i] << endl;
                        count++;
                        break;
                    }
                    alpha[k] = 1;
                }
            }
        }
        return count;
    }
};
