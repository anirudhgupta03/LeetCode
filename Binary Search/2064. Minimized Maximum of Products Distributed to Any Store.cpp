//Ref: https://www.youtube.com/watch?v=Wdh4negJaq0
class Solution {
public:
    bool isPossible(int products, int n, vector<int> &quantities){
        
        int count = 0;
        for(int i = 0; i < quantities.size(); i++){
            count += quantities[i]/products;
            if(quantities[i] % products != 0) count++;
        }
        if(count <= n){
            return true;
        }
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int lo = 1, hi = *max_element(quantities.begin(),quantities.end());
        int ans;
        
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(isPossible(mid, n, quantities)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};
