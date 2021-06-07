//Brute Force Approach
//Use Sorting
//Time Complexity - O(NlogN)
//Space Complexity - O(1)

//Optimal Approach
//Ref: https://www.youtube.com/watch?v=pnx5JA9LNM4
//Time Complexity - O(N)
//Space Complexity - O(NlogN)
class Solution {
public:
    #define ll long long
    vector<int> singleNumber(vector<int>& nums) {
        
        ll xorsum = 0;
        
        for(ll val: nums){
            xorsum ^= val;
        }
        
        int a = 0, b = 0;
        
        ll rsbm = xorsum & (~(xorsum-1));
        
        for(ll val: nums){
            
            if((val & rsbm) == 0){
                a ^= val;
            }
            else{
                b ^= val;
            }
        }
        vector<int> res = {a,b};
        return res;
    }
};
