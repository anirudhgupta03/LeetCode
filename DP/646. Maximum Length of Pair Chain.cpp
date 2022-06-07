class Solution {
public:
    bool static cmp(vector<int> &v1, vector<int> &v2){
        return v1[1] < v2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(), pairs.end(), cmp);
        
        int e = pairs[0][1];
        
        int count = 1;
        
        for(int i = 1; i < pairs.size(); i++){
            if(pairs[i][0] > e){
                e = pairs[i][1];
                count++;
            }
        }
        return count;
    }
};
