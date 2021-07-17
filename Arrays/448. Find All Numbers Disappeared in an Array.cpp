//Method - 1
//Time Complexity - O(N)
//Space Complexity - O(N)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> res;
        
        int n = nums.size();
        
        vector<int> count(n+1,0);
        
        for(int i = 0; i < n; i++){
            count[nums[i]]++;
        }
        
        for(int i = 1; i <= n; i++){
            if(count[i] == 0){
                res.push_back(i);
            }
        }
        
        return res;
    }
};

//Method - 2
//Time Complexity - O(N)
//Space Complexity - O(1)
//Ref: https://www.youtube.com/watch?v=jSfDPVIYe1s
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[abs(nums[i])-1] > 0){
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                res.push_back(i + 1);
            }
        }
        
        return res;
    }
};
