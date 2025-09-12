//Ref1: https://www.youtube.com/watch?v=nGGp5XBzC4g
//Ref2: https://www.youtube.com/watch?v=yDYE7vk3ve4
class Solution {
public:
    int findPeakColRow(int col, vector<vector<int>>& mat){
        int ind = -1, maxCol = INT_MIN;
        for(int i = 0; i < mat.size(); i++){
            if(mat[i][col] > maxCol){
                ind = i;
                maxCol = mat[i][col];
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int lo = 0, hi = n - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int peakColRow = findPeakColRow(mid, mat);
            int preEle = (mid > 0) ? mat[peakColRow][mid - 1] : -1;
            int nextEle = (mid + 1 < n) ? mat[peakColRow][mid + 1] : -1;
            if(mat[peakColRow][mid] > preEle && mat[peakColRow][mid] > nextEle){
                return {peakColRow, mid};
            }
            else if(preEle > mat[peakColRow][mid]){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return {-1, -1};
    }
};
