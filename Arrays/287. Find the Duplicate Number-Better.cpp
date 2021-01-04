class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int arr[n+1];
        memset(arr,0,sizeof(arr));
        int ans;
        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
            if(arr[nums[i]]!=1){
                ans= nums[i];
                    break;
            }
        }
        return ans;
    }
};
