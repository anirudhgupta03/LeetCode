//Method - 1
//TLE
//Ref: https://leetcode.com/problems/palindrome-pairs/discuss/79215/Easy-to-understand-AC-C%2B%2B-solution-O(n*k2)-using-map
class Solution {
public:
    bool isPalindrome(string s){
        int lo = 0, hi = s.size() - 1;
        while(lo < hi){
            if(s[lo] != s[hi]){
                return false;
            }
            lo++;
            hi--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        unordered_map<string,int> umap;
        
        for(int i = 0; i < words.size(); i++){
            string key = words[i];
            reverse(key.begin(), key.end());
            umap[key] = i;
        }
        
        vector<vector<int>> res;
        
        if(umap.find("") != umap.end()){
            for(int i = 0; i < words.size(); i++){
                if(i == umap[""]) continue;
                if(isPalindrome(words[i])){
                    res.push_back({i, umap[""]});
                    res.push_back({umap[""], i});
                }
            }
        }
        
        for(int i = 0; i < words.size(); i++){
            if(umap.find(words[i]) != umap.end() && umap[words[i]] != i){
                res.push_back({i, umap[words[i]]});
            }
        }
        
        for(int i = 0; i < words.size(); i++){
            string curr = words[i];
            for(int cut = 1; cut < curr.size(); cut++){
                
                string left = curr.substr(0, cut), right = curr.substr(cut);
                
                if(isPalindrome(left)){
                    if(umap.find(right) != umap.end() && umap[right] != i){
                        res.push_back({umap[right], i});
                    }
                }
                if(isPalindrome(right)){
                    if(umap.find(left) != umap.end() && umap[left] != i){
                        res.push_back({i, umap[left]});
                    }
                }
            }
        }
        return res;
    }
};

//Method - 2
