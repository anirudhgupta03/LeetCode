//Method - 1
//TC: O(N)
//SC: O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for(int &ele: arr){
            if(ele <= k){
                k++;
            }
            else{
                break;
            }
        }
        return k;
    }
};

//Method - 2
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

//Method - 3
//Ref: https://www.youtube.com/watch?v=uZ0N_hZpyps&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=16
//TC: O(log N)
//SC: O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int lo = 0, hi = n - 1;
        int ans = k;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int elementsMissing = arr[mid] - (mid + 1);
            if(elementsMissing < k){
                ans = k + mid + 1;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
};
