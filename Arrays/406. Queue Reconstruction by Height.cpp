class Solution {
public:
    bool static cmp(vector<int> &v1, vector<int> &v2){
        if(v1[0] == v2[0]){
            return v1[1] < v2[1];
        }
        return v1[0] > v2[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& v) {
        
        sort(v.begin(), v.end(),cmp);

        vector<vector<int>> res;

        for(int i = 0; i < v.size(); i++){
            res.insert(res.begin() + v[i][1], {v[i][0], v[i][1]});
        }
        return res;
    }
};
