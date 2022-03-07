//Ref: https://www.youtube.com/watch?v=2lb0qFs-cRg
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        
        vector<int> left, right;
        
        left.push_back(arr[0]);
        int n = arr.size();
    
        for(int i = 1; i < n; i++){
            if(arr[i] >= left.back()){
                left.push_back(arr[i]);
            }
            else{
                break;
            }
        }
        
        right.push_back(arr[n - 1]);
        for(int i = n - 2; i >= 0; i--){
            if(arr[i] <= right.back()){
                right.push_back(arr[i]);
            }
            else{
                break;
            }
        }
        
        if(n == 1) return 0;
        else if(left.size() == n || right.size() == n){
            return 0;
        }
        reverse(right.begin(), right.end());
        int mini = min(n - left.size(), n - right.size());
        
        for(int i = 0; i < left.size(); i++){
            int lo = 0, hi = right.size() - 1;
            int ans = right.size();
            while(lo <= hi){
                int mid = (lo + hi)/2;
                if(right[mid] >= left[i]){
                    ans = mid;
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }
            mini = min(mini, (n - i - 1) - ((int)right.size() - ans));
        }
        return mini;
    }
};
