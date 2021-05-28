class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
	    int alpha1[26] = {0};
	    
	    for(int i = 0; i < p.size(); i++){
	        alpha1[p[i] - 'a']++;
	    }
	    
        vector<int> res;
        
        int alpha2[26] = {0};
        
        int i = 0, j = 0;
        
        while(j < s.size()){
            
            alpha2[s[j]-'a']++;
            
            if(j - i + 1 < p.size()){
                j++;
            }
            else if(j - i + 1 == p.size()){
                
                bool flag = true;
                for(int i = 0; i < 26; i++){
                    if(alpha1[i] != alpha2[i]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    res.push_back(i);
                }
                
                alpha2[s[i]-'a']--;
                i++;
                j++;
            }
        }
	    return res;
    }
};
