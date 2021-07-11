class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        vector<pair<int,int>> v(26,{-1,-1});
        
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            
            int j = s[i] - 'a';
            
            if(v[j].first == -1){
                v[j] = {i,i};
            }
            else{
                v[j].second = i;
            }
        }
        
        unordered_set<char> us;
        int count = 0;
        
        for(int i = 0; i < 26; i++){
            
            int start = v[i].first, end = v[i].second;
            
            for(int j = start + 1; j < end; j++){
                us.insert(s[j]);
            }
            
            count += us.size();
            us.clear();
        }
        
        return count;
    }
};
