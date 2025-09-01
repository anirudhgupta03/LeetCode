//Ref: https://www.youtube.com/watch?v=nP_ns3uSh80&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int ele, cnt= 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(cnt == 0){
                ele = nums[i];
            }
            
            if(nums[i] == ele){
                cnt++;
            }
            else{
                cnt--;
            }
            
            
        }
        return ele;
    }
};
