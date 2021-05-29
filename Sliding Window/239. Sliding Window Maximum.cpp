class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> res;
        
        deque<int> dq;
        
        int i = 0, j = 0;
        
        while(j < nums.size()){
            
            if(dq.empty()){
                dq.push_back(nums[j]);
            }
            else if(dq.back() < nums[j]){
                
                while(!dq.empty() && dq.back() < nums[j]){
                    dq.pop_back();
                }
                
                dq.push_back(nums[j]);
            }
            else{
                dq.push_back(nums[j]);
            }
            
            if(j - i + 1  < k){
                j++;
            }
            else if(j - i + 1 == k){
                
                res.push_back(dq.front());
                
                if(nums[i] == dq.front()){
                    dq.pop_front();
                }
                i++;
                j++;
            }
        }
        return res;
    }
};
