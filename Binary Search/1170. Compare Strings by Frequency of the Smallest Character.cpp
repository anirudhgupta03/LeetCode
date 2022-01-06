class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        int n = words.size();
        
        vector<int> temp(n,0);
        
        for(int i = 0; i < n; i++){
            int alpha[26] = {0};
            for(int j = 0; j < words[i].size(); j++){
                alpha[words[i][j] - 'a']++;
            }
            for(int j = 0; j < 26; j++){
                if(alpha[j] != 0){
                    temp[i] = alpha[j];
                    break;
                }
            }
        }
        
        sort(temp.begin(),temp.end());
        
        vector<int> res(queries.size());
        
        for(int i = 0; i < queries.size(); i++){
            int alpha[26] = {0};
            for(int j = 0; j < queries[i].size(); j++){
                alpha[queries[i][j] - 'a']++;
            }
            int t;
            for(int j = 0; j < 26; j++){
                if(alpha[j] != 0){
                    t = alpha[j];
                    break;
                }
            }
            
            int lo = 0, hi = n - 1;
            int ans = -1;
            while(lo <= hi){
                
                int mid = (lo + hi)/2;
                if(temp[mid] <= t){
                    ans = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            
            res[i] = n - ans - 1;
        }
        return res;
    }
};
