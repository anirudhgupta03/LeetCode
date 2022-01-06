//https://www.codingninjas.com/codestudio/problems/common-element-in-rows_975481?leftPanelTab=0
int smallestCommonElement(int m, int n, vector<vector<int>>& mat) {
    
    for(int j = 0; j < n; j++){
        int ele = mat[0][j];
        bool flag = true;
        for(int i = 1; i < m; i++){
            int lo = 0, hi = n - 1;
            int ind = -1;
            while(lo <= hi){
                int mid = (lo + hi)/2;
                if(mat[i][mid] == ele){
                    ind = mid;
                    break;
                }
                else if(mat[i][mid] > ele){
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }
            
            if(ind == -1){
                flag = false;
                break;
            }
        }
        if(flag){
            return ele;
        }
    }
    return -1;
}
