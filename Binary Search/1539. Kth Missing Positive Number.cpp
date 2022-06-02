class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        int lo = 0, hi = arr.size() - 1, ans = -1;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(arr[mid] - mid - 1 >= k){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        
        if(ans == -1){
            int diff = arr[n - 1] - n;
            return arr[n - 1] + k - diff;
        }
        else{
            int diff = arr[ans] - ans - 1;
            return arr[ans] - (diff - k) - 1;    
        }
    }
};
