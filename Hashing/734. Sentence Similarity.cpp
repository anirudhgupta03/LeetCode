//https://www.lintcode.com/problem/856/
class Solution {
public:
    /**
     * @param words1: a list of string
     * @param words2: a list of string
     * @param pairs: a list of string pairs
     * @return: return a boolean, denote whether two sentences are similar or not
     */
    bool isSentenceSimilarity(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs) {
        
        map<pair<string,string>,int> mp;

        for(int i = 0; i < pairs.size(); i++){
            mp[{pairs[i][0], pairs[i][1]}]++;
        }

        if(words1.size() != words2.size()){
            return false;
        }

        for(int i = 0; i < words1.size(); i++){
            string s1 = words1[i], s2 = words2[i];
            if(!(s1 == s2 || mp.find({s1,s2}) != mp.end() || mp.find({s2,s1}) != mp.end())){
                return false;
            }
        }
        return true;
    }
};
