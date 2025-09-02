//Ref: https://www.youtube.com/watch?v=vwZj1K0e9U8&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=19
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int ele1 = INT_MIN, ele2 = INT_MIN,count1= 0, count2=0;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] == ele1){
                count1++;
            }
            else if(nums[i] == ele2){
                count2++;
            }
            else if(count1 == 0){
                ele1 = nums[i];
                count1++;
            }
            else if(count2 == 0){
                ele2 = nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        int cnt1 =0,cnt2=0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == ele1){
                cnt1++;
            }
            else if(nums[i] == ele2){
                cnt2++;
            }
        }
        vector<int> v;
        if(cnt1 > nums.size()/3){
            v.push_back(ele1);
        }
        if(cnt2 > nums.size()/3){
            v.push_back(ele2);
        }
        
        return v;
    }
};
