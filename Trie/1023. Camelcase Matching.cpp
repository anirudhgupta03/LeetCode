class Solution {
public:
    bool isMatching(string s1, string s2){
        
        int ind1 = 0, ind2 = 0;
        
        while(ind1 < s1.size() && ind2 < s2.size()){
            
            if(isupper(s1[ind1])){
                if(isupper(s2[ind2])){
                    if(s1[ind1] != s2[ind2]){
                        return false;
                    }
                    else{
                        ind1++;
                        ind2++;
                    }
                }
                else{
                    return false;
                }
            }
            else{
                if(!isupper(s2[ind2])){
                    if(s1[ind1] != s2[ind2]){
                        ind1++;
                    }
                    else{
                        ind1++;
                        ind2++;
                    }
                }
                else{
                    ind1++;
                }
            }
        }
        
        if(ind2 == s2.size()){
            while(ind1 < s1.size() && !isupper(s1[ind1])){
                ind1++;
            } 
            if(ind1 == s1.size())
            return true;
        }
        return false;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        
        vector<bool> res;
        
        for(int i = 0; i < queries.size(); i++){
            if(isMatching(queries[i], pattern)){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }
        return res;
    }
};
