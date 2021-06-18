class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        vector<int> nsl(n);
        vector<int> nsr(n);
        
        nsl[0] = -1;
        
        stack<int> s;
        
        s.push(0);
        
        for(int i = 1; i < n; i++){
            
            if(heights[i] > heights[s.top()]){
                nsl[i] = s.top();
            }
            else{
                
                while(!s.empty() && heights[s.top()] >= heights[i]){
                    s.pop();
                }
                
                if(!s.empty()){
                    nsl[i] = s.top();
                }
                else{
                    nsl[i] = -1;
                }
            }
            s.push(i);
        }
        
        nsr[n-1] = n;
        
        while(s.size()){
            s.pop();
        }
        s.push(n-1);
        
        for(int i = n - 2; i >= 0; i--){
            
            if(heights[i] > heights[s.top()]){
                nsr[i] = s.top();
            }
            else{
                
                while(!s.empty() && heights[s.top()] >= heights[i]){
                    s.pop();
                }
                
                if(!s.empty()){
                    nsr[i] = s.top();
                }
                else{
                    nsr[i] = n;
                }
            }
            s.push(i);
        }
        
        int maxArea = INT_MIN;
        
        for(int i = 0; i < n; i++){
            maxArea = max((nsr[i]-nsl[i]-1)*heights[i],maxArea);
        }
        
        return maxArea;
    }
};
