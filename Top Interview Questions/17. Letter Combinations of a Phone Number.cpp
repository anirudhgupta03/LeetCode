// Time Complexity : O(4^N*N), where N, is the length of input string. 4^N for building every possible string combination and N to form the string by joining each character.. Here, 4 is chosen assuming the worst case where each digit will be 7 or 9 and we would have 4*4*4*4 total string combinations.
// Space Complexity : O(N), the max recursion depth will be N, where N is the length of input string. If the space required for ans is considered as well, the complexity will be O(4^N).
class Solution {
public:
    void solve(int ind, vector<string> &res, string &temp, unordered_map<char,string> &umap, string &digits){
        
        if(ind == digits.size()){
            res.push_back(temp);
            return;
        }
        
        for(int i = 0; i < umap[digits[ind]].size(); i++){
            temp.push_back(umap[digits[ind]][i]);
            solve(ind+1,res,temp,umap,digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char,string> umap;
        umap['2'] = "abc";
        umap['3'] = "def";
        umap['4'] = "ghi";
        umap['5'] = "jkl";
        umap['6']=  "mno";
        umap['7'] = "pqrs";
        umap['8'] = "tuv";
        umap['9'] = "wxyz";
        
        vector<string> res;
        
        if(digits.size() == 0){
            return res;
        }
        string temp;
        
        solve(0,res,temp,umap, digits);
        
        return res;
    }
};
