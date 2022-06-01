//https://www.codingninjas.com/codestudio/problems/kth-missing-element_893215?leftPanelTab=0
//https://leetcode.ca/all/1060.html
int missingK(vector < int > a, int n, int k) {
    
    int lo = 0, hi = n - 1;
    int ans = -1;
    int start = n - 1;
    
    while(lo <= hi){
        
        int mid = (lo + hi)/2;
        
        int reqele = a[0] + mid, currele = a[mid];
        
        int missele = currele - reqele;
        
        if(missele >= k){
            start = mid - 1;
            hi = mid - 1;
        }
        else{
            ans = missele;
            lo = mid + 1;
        }
    } 
    return a[start] + k - ans;
}
