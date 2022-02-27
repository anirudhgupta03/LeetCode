class Solution {
public:
    int minSteps(string s, string t) {
        
        vector<int> alpha1(26,0), alpha2(26,0);
        
        for(int i = 0; i < s.size(); i++){
            alpha1[s[i] - 'a']++;
        }
        for(int j = 0; j < t.size(); j++){
            alpha2[t[j] - 'a']++;
        }
        
        int mcnt1 = 0, mcnt2 = 0;
        
        for(int i = 0; i < 26; i++){
            if(alpha1[i]){
                if(alpha2[i] <= alpha1[i]){
                    mcnt1 += alpha1[i] -alpha2[i];
                }
            }
            if(alpha2[i]){
                if(alpha1[i] <= alpha2[i]){
                    mcnt2 += alpha2[i] - alpha1[i];
                }
            }
        }
        return mcnt1 + mcnt2;
    }
};
