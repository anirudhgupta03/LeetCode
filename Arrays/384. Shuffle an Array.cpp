class Solution {
public:
    vector<int> original;
    vector<int> ran;
    Solution(vector<int>& nums) {
        original = nums;
        ran = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(ran.empty()){
            return ran;
        }
        
        int n = ran.size();
        for(int i = n; i > 0; i--){
            swap(ran[i-1],ran[rand()%i]);
        }
        return ran;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
