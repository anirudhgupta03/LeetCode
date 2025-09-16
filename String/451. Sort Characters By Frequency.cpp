class Solution {
public:
    bool static cmp(pair<int,char> &p1, pair<int,char> &p2){
        return p1.first > p2.first;
    }
    string frequencySort(string s) {
        int len = s.length();
        unordered_map<char,int> umap;
        for(char &ch: s){
            umap[ch]++;
        }
        vector<pair<int,char>> v;
        for(auto &x: umap){
            v.push_back({x.second, x.first});
        }
        sort(v.begin(), v.end(), cmp);
        string res;
        for(auto &x: v){
            int freq = x.first;
            while(freq--){
                res.push_back(x.second);
            }
        }
        return res;
    }
};
