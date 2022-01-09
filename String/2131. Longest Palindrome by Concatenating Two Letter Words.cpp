class Solution {
public:
    bool isPalindrome(string s){
        
        int lo = 0, hi = s.size() - 1;
        
        while(lo <= hi){
            if(s[lo] != s[hi]){
                return false;
            }
            lo++;
            hi--;
        }
        return true;
    }
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string,int> umap;
        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            reverse(s.begin(),s.end());
            if(umap.find(s) != umap.end()){
                ans += 4;
                umap[s]--;
                if(umap[s] == 0) umap.erase(s);
            }
            else{
                umap[words[i]]++;
            }
        }
        int count = 0;
        for(auto x: umap){
            if(isPalindrome(x.first)){
                if(x.second > count){
                    count = x.second;
                }
            }
        }
        return ans + 2*count;
    }
};
