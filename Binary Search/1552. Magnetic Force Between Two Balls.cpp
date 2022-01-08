//Similar to Aggressive Cows
class Solution {
public:
    bool isPossible(vector<int> &position, int force, int m){
        
        int count = 1;
        int prev = position[0];
        
        for(int i = 1; i < position.size(); i++){
            if(position[i] - prev >= force){
                prev = position[i];
                count++;
            }
        }
        
        if(count >= m){
            return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        
        int n = position.size();
        
        sort(position.begin(),position.end());
        
        int lo = 1, hi = position[n - 1];
        
        int ans;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(isPossible(position, mid, m)){
                lo = mid + 1;
                ans = mid;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
};
