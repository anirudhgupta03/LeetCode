//Method - 1
//Time Complexity - O(N^2logN)
//Space Complexity - O(N)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        
        if(nums.size() < 3){
            return res;
        }
        
        set<vector<int>> s;
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i <= nums.size() - 3; i++){
            
            int l = i + 1, r = nums.size() - 1;
            
            while(l < r){
                
                int sum = nums[i] + nums[l] + nums[r];
                
                if(sum == 0){
                    vector<int> temp = {nums[i],nums[l],nums[r]};
                    s.insert(temp);
                    l++;
                    r--;
                }
                else if(sum <  0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        
        for(auto x: s){
            res.push_back(x);
        }
        
        return res;
    }
};

//Method - 2
//Optimal Approach
//Time Complexity - O(N^2)
//Space Complexity - O(1)
//Ref: https://leetcode.com/problems/3sum/discuss/7380/Concise-O(N2)-Java-solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        
        if(nums.size() < 3){
            return res;
        }
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i <= nums.size() - 3; i++){
            
            if(i > 0 && (nums[i] == nums[i-1])){
                continue;
            }
            int l = i + 1, r = nums.size() - 1;
            
            while(l < r){
                
                int sum = nums[i] + nums[l] + nums[r];
                
                if(sum == 0){
                    vector<int> temp = {nums[i],nums[l],nums[r]};
                    res.push_back(temp);
                    
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
                }
                else if(sum <  0){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        
        return res;
    }
};
