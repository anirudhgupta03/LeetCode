//Method - 1
//TC: O(M + N)
//SC: O(M + N)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> res;
        
        int i = 0, j = 0;
        
        while(i < m && j < n){
            
            if(nums1[i] < nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }
            else{
                res.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i < m){
            res.push_back(nums1[i]);
            i++;
        }
        while(j < n){
            res.push_back(nums2[j]);
            j++;
        }
        
        nums1.clear();
        nums1 = res;
    }
};

//Method - 2
//Ref: https://www.youtube.com/watch?v=C4oBXLr3zos
//TC: O(M + N)
//SC: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};
