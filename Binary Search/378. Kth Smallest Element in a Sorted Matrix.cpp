class Solution {
public:
    int countOfElementsLessThanOrEqualToMid(int ele, vector<vector<int>> &matrix){
        
        int count = 0;
        
        for(int i = 0; i < matrix.size(); i++){
            int ans = -1, lo = 0, hi = matrix.size() - 1;
            while(lo <= hi){
                int mid = (lo + hi)/2;                
                if(matrix[i][mid] <= ele){
                    ans = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            count += ans + 1;
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        
        int lo = INT_MAX, hi = INT_MIN;
        
        for(int i = 0; i < n; i++){
            lo = min(lo, matrix[i][0]);
            hi = max(hi, matrix[i][n - 1]);
        }
        
        int ans;
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            
            if(countOfElementsLessThanOrEqualToMid(mid, matrix) >= k){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};
