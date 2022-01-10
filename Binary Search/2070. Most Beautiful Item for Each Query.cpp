class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        sort(items.begin(), items.end());
        
        vector<int> beauty(items.size());
        beauty[0] = items[0][1];
        
        for(int i = 1; i < items.size(); i++){
            beauty[i] = max(beauty[i-1], items[i][1]);
        }
        
        vector<int> ans(queries.size());
        
        for(int i = 0; i < queries.size(); i++){
            
            int lo = 0, hi = items.size() - 1, ind = -1;
            
            while(lo <= hi){
                int mid = (lo + hi)/2;
                if(items[mid][0] <= queries[i]){
                    ind = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            if(ind == -1){
                ans[i] = 0;
            }
            else{
                ans[i] = beauty[ind];
            }
        }
        return ans;
    }
};
