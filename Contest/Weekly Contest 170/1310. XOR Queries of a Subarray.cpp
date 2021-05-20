class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        vector<int> temp(arr.size()+1);
        
        int t = 0;
        
        temp[0] = 0;
        
        for(int i = 1; i <=arr.size(); i++){
            t = t ^ arr[i-1];
            temp[i] = t;
        }
        
        vector<int> res;
        
        for(int i = 0; i < queries.size(); i++){
            
            int l = queries[i][0], r = queries[i][1];
            
            res.push_back(temp[l]^temp[r+1]);
        }
        
        return res;
    }
};
