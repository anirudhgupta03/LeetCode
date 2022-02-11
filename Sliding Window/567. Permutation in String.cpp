class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int l1 = s1.size(), l2 = s2.size();
        
        if(l2 < l1){
            return false;
        }
        
        vector<int> alpha1(26, 0);
        
        for(int i = 0; i < s1.size(); i++){
            alpha1[s1[i] - 'a']++;
        }
        
        vector<int> alpha2(26, 0);
        
        for(int i = 0; i < l1; i++){
            alpha2[s2[i] - 'a']++;
        }
        
        int lo = 0, hi = l1;
        
        while(hi < l2){
            bool flag = true;
            for(int i = 0; i < 26; i++){
                if(alpha1[i] != alpha2[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return true;
            }
            alpha2[s2[lo] - 'a']--;
            lo++;
            alpha2[s2[hi] - 'a']++;
            hi++;
        }
        bool flag = true;
        for(int i = 0; i < 26; i++){
            if(alpha1[i] != alpha2[i]){
                flag = false;
                break;
            }
        }
        if(flag){
            return true;
        }
        return false;
    }
};
