class Solution {
public:
    int findMin(vector<int>& A) {
        
        int n = A.size();
    
        if(n == 1){
            return A[0];
        }
        int lo = 0, hi = n - 1;

        while(lo <= hi){

            int mid = (lo + hi)/2;
            int prev = (mid+n-1)%n;
            int next = (mid + n - 1)%n;

            if(A[mid] < A[prev] && A[mid] < A[next]){
                return A[mid];
            }
            else if(A[mid] < A[n-1]){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return 0;
    }
};
