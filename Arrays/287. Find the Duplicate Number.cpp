//Method - 1
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

//Method - 2
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[abs(nums[i]) - 1] < 0){
                return abs(nums[i]);
            }
            else{
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i])-1];
            }
        }
        return 0;
    }
};

//Method - 3
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = nums[0], fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        slow = nums[0];
        
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};
