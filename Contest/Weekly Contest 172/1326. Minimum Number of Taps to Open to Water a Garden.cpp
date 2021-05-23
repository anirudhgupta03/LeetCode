//Greedy Approach
//Similar to https://practice.geeksforgeeks.org/problems/410d51d667ab93f2219b15126f001f32e8bb029e/1/
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        vector<int> temp(n+1,-1);
        
        for(int i = 0; i < ranges.size(); i++){
            
            int l = max(0,i - ranges[i]);
            int r = min(n,i+ranges[i]);
            
            for(int j = l ; j <= r; j++){
                temp[j] = max(temp[j],r);
            }
        }
        
        int count = 0;
        
        int i = 0;
        
        while(i < n){
            
            i = temp[i];
            
            if(i == n){
                break;
            }
            
            if(i == temp[i]){
                return -1;
            }
            count++;
        }
        count++;
        return count;
    }
};
