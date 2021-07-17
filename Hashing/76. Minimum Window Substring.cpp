class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int> mp1, mp2;
        
        for(int i = 0; i < t.size(); i++){
            mp1[t[i]]++;
        }
        
        int k = mp1.size(), l = 0, r = 0, minLen = INT_MAX, count = 0;
        string ans;
        
        while(r < s.size()){
            
            mp2[s[r]]++;
            
            if(mp1.find(s[r]) != mp1.end()){
                if(mp1[s[r]] == mp2[s[r]]){
                    count++;
                }
            }
            
            if(count == k){
                
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    ans = s.substr(l,r-l+1);
                }
                
                while(l < r){
                    mp2[s[l]]--;
                    
                    if(mp1.find(s[l]) != mp1.end() && mp1[s[l]] > mp2[s[l]]){
                        count--;
                        if(mp2[s[l]] == 0){
                            mp2.erase(s[l]);
                        }
                        l++;
                        break;
                    }
                    l++;
                    if(r - l + 1 < minLen){
                        minLen = r - l + 1;
                        ans = s.substr(l,r-l+1);
                    }
                }
            }
            
            r++;
        }
        
        return ans;
    }
};
