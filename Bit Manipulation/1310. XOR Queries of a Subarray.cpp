class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();
        vector<int> a(n+1);
        a[0] = 0;
        
        for(int i = 0; i < n; i++){
            a[i+1] = a[i]^arr[i];
        }
        
        vector<int> v;
        for(int i = 0; i < queries.size(); i++)
        {
            int l = queries[i][0], r = queries[i][1];
            v.push_back(a[r+1]^a[l]);
        }
        return v;
    }
};
