class RangeFreqQuery {
public:
    unordered_map<int,vector<int>> umap;
    RangeFreqQuery(vector<int>& arr) {
        umap.clear();
        for(int i = 0; i < arr.size(); i++){
            umap[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        
        int leftInd = -1, rightInd = -1;
        
        int lo = 0, hi = umap[value].size() - 1;
        
        int ans = 0;
        
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(umap[value][mid] >= left){
                leftInd = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        
        lo = 0, hi = umap[value].size() - 1;
        
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(umap[value][mid] <= right){
                rightInd = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        
        if(leftInd <= rightInd && leftInd != -1 && rightInd != -1){
            return rightInd - leftInd + 1;
        }
        else{
            return 0;
        }
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
