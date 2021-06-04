//Time Complexity - O(N)
//Space Complxity - O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int l = 0, r = height.size() - 1;
        
        int max_area = INT_MIN;
        
        while(l < r){
            
            if(height[l] > height[r]){
                max_area = max(max_area,(r-l)*height[r]);
                r--;
            }
            else{
                max_area = max(max_area,(r-l)*height[l]);
                l++;
            }
        }
        return max_area;
    }
};
