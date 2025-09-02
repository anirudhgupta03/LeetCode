//Ref: https://www.youtube.com/watch?v=DhFh8Kw7ymk&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=20
//Method - 1
//Time Complexity - O(N^2logN)
//Space Complexity - O(N)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        set<vector<int>> st;
        for(int i = 0; i < n - 1; i++){
            unordered_set<int> us;
            for(int j = i + 1; j < n; j++){
                int sum = -1*(arr[i] + arr[j]);
                if(us.find(sum) != us.end()){
                    vector<int> temp = {arr[i], arr[j], sum};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                us.insert(arr[j]);
            }
        }
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};

//Method - 2
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

//Method - 3
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
