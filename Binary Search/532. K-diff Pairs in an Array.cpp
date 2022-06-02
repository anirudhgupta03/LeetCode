//Method - 1
//TC - O(N)
//SC - O(N)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int, int> umap;
        
        for(int x: nums){
            umap[x]++;
        }
        
        int count = 0;
        
        for(auto x: umap){
            if(k == 0){
                if(x.second > 1) count++;
            }
            else{
                if(umap.find(x.first + k) != umap.end()){
                    count++;
                }
            }
        }
        return count;
    }
};

//Method - 2
//TC - O(NlogN)
//SC - O(1)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        int count = 0;
        
        for(int i = 0; i < nums.size() - 1; i++){
            
            if(i != 0 && nums[i] == nums[i-1]) continue;
            
            int temp = nums[i] + k;
            
            int lo = i + 1, hi = nums.size() - 1;
            
            while(lo <= hi){
                
                int mid = (lo + hi)/2;
                
                if(nums[mid] > temp){
                    hi = mid - 1;
                }
                else if(nums[mid] == temp){
                    count++;
                    break;
                }
                else{
                    lo = mid + 1;
                }
            }
        }
        return count;
    }
};
