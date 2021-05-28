class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
	    int alpha1[26] = {0};
	    
	    for(int i = 0; i < p.size(); i++){
	        alpha1[p[i] - 'a']++;
	    }
	    
        vector<int> res;
        
	    int l = 0, r = 0;
	    
	    int alpha2[26] = {0};
	    
	    int mct = 0, dct = p.size();
	    
	    int count = 0;
	    
	    while(r < s.size()){
	        
	        alpha2[s[r] - 'a']++;
	        
	        if(alpha2[s[r] - 'a'] <= alpha1[s[r] - 'a']){
	            mct++;
	        }
	        else if(alpha1[s[r]-'a'] == 0){
	            l = r + 1;                                                                                                 
	            for(int i = 0; i < 26; i++){
	                alpha2[i] = 0;
	            }
	            mct = 0;
	        }
	        else if(alpha1[s[r]-'a'] != 0){
	            
                while(l < r && s[l] != s[r]){
                    alpha2[s[l]-'a']--;
                    if(alpha2[s[l]-'a'] < alpha1[s[l]-'a']){
                        mct--;
                    }
                    l++;
                }
                alpha2[s[l]-'a']--;
                l++;
	        }
	        
	        //cout << mct << endl;
	        
	        if(mct == dct){
	            //cout << "Hi" << endl;
                res.push_back(l);
	            count++;
	            mct--;
	            alpha2[s[l] - 'a']--;
	            l++;
	        }
	        //cout << count << endl;
	        r++;
	    }
	    
	    return res;
    }
};
