//Method - 1
//TC: O(2*N)
//SC: O(2*N)
class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        int left[n], right[n];
        
        left[0] = height[0];
        
        for(int i = 1; i < n; i++){
            left[i] = max(left[i - 1], height[i]);
        }
        
        right[n - 1] = height[n - 1];
        
        for(int i = n - 2; i >= 0; i--){
            right[i] = max(right[i + 1], height[i]);
        }
        
        int waterTrapped = 0;
        
        for(int i = 1; i < n - 1; i++){
            if(left[i] > height[i] && right[i] > height[i]){
                waterTrapped += min(left[i], right[i]) - height[i];
            }
        }
        
        return waterTrapped;
    }
};

//Method - 2
//TC: O(N)
//SC: O(1)
//Ref: https://www.youtube.com/watch?v=m18Hntz4go8
class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        int lo = 0, hi = n - 1;
        
        int sum = 0, lmax = INT_MIN, rmax = INT_MIN;
        
        while(lo <= hi){
            
            if(height[lo] < height[hi]){
                lmax = max(lmax, height[lo]);
                sum += lmax - height[lo];
                lo++;
            }
            else{
                rmax = max(rmax, height[hi]);
                sum += rmax - height[hi];
                hi--;
            }
        }
        return sum;
    }
};
