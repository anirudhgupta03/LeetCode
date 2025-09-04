//Ref: https://www.youtube.com/watch?v=0e4bZaP3MDI&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=27
#define ll long long
class Solution {
public:
    void merge(int lo, int mid, int hi, vector<int>& nums){
        vector<ll> lr, rr;
        for(int i = lo; i <= mid; i++) lr.push_back(nums[i]);
        for(int i = mid + 1; i <= hi; i++) rr.push_back(nums[i]);
        int ptr1 = 0, ptr2 = 0, ptr3 = lo;
        while(ptr1 < lr.size() && ptr2 < rr.size()){
            if(lr[ptr1] > rr[ptr2]){
                nums[ptr3++] = rr[ptr2];
                ptr2++;
            }
            else{
                nums[ptr3++] = lr[ptr1];
                ptr1++;
            }
        }
        while(ptr1 < lr.size()){
            nums[ptr3++] = lr[ptr1];
            ptr1++;
        }
        while(ptr2 < rr.size()){
            nums[ptr3++] = rr[ptr2];
            ptr2++;
        }
    }
    int countPairs(int lo, int mid, int hi, vector<int> &nums){
        int cnt = 0, right = mid + 1;
        for(int i = lo; i <= mid; i++){
            while(right <= hi && nums[i] > (ll)2*nums[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    int mergeSort(int lo, int hi, vector<int>& nums){
        if(lo >= hi){
            return 0;
        }
        int mid = lo + (hi - lo)/2;
        int cnt = 0;
        cnt += mergeSort(lo, mid, nums);
        cnt += mergeSort(mid + 1, hi, nums);
        cnt += countPairs(lo, mid, hi, nums);
        merge(lo, mid, hi, nums);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(0, n - 1, nums);
    }
};
