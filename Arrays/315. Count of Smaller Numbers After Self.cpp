//Ref: https://www.youtube.com/watch?v=VOv2vY_Hq8Y
class Solution {
public:
    void merge(vector<int> &nums, vector<int> &originalIndex, int l, int mid, int r, vector<int> &res){
        
        int n1 = mid - l + 1, n2 = r - mid;
        
        vector<int> left(n1), right(n2);
        
        for(int i = l; i <= mid; i++){
            left[i-l] = originalIndex[i];
        }
        
        for(int i = mid + 1; i <= r; i++){
            right[i-mid-1] = originalIndex[i];
        }
        
        int p1 = 0, p2 = 0, p3 = l, rightCount = 0;
        
        while(p1 < n1 && p2 < n2){
            if(nums[left[p1]] <= nums[right[p2]]){
                originalIndex[p3] = left[p1];
                res[left[p1]] += rightCount;
                p1++;
                p3++;
            }
            else{
                originalIndex[p3] = right[p2];
                rightCount++;
                p2++;
                p3++;
            }
        }
        
        while(p1 < n1){
            originalIndex[p3] = left[p1];
                res[left[p1]] += rightCount;
                p1++;
                p3++;
        }
        
        while(p2 < n2){
            originalIndex[p3] = right[p2];
            p2++;
            p3++;
        }
    }
    void mergesort(vector<int> &nums, vector<int> &originalIndex, int l, int r, vector<int> &res){
        if(l < r){
            int mid = (l + r)/2;
            mergesort(nums,originalIndex,l,mid,res);
            mergesort(nums,originalIndex,mid+1,r,res);
            merge(nums,originalIndex,l,mid,r,res);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
    
        int n = nums.size();
        
        vector<int> originalIndex(n);
        vector<int> res(n);
        
        for(int i = 0; i < n; i++){
            originalIndex[i] = i;
        }
        
        mergesort(nums,originalIndex,0,n-1,res);
        
        return res;
    }
};
