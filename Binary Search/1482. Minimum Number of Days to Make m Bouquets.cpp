//Excellent Question
class Solution {
public:
    
    bool isPossible(int day, vector<int> &bloomDay, int m, int k){
        
        int count = 0;
        int ans = INT_MIN;
        int b_count = 0;
        
        for(int i = 0; i < bloomDay.size(); i++){
            
            if(bloomDay[i] <= day){
                count++;
            }
            else{
                if(count >= k){
                    b_count += count/k;
                }
                count = 0;
            }
        }
        
        if(count >= k){
            b_count += count/k;
        }
        if(b_count >= m){
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int lo = INT_MAX, hi = INT_MIN;
        
        for(int i = 0; i < bloomDay.size(); i++){
            lo = min(lo,bloomDay[i]);
            hi = max(hi,bloomDay[i]);
        }
        
        int ans = -1;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            if(isPossible(mid,bloomDay,m,k)){
                hi = mid - 1;
                ans = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    #define ll long long
    int numberofBouquets(int days, vector<int> &bloomDay, int k){
        
        ll count = 0, temp = 0;
        
        for(int i = 0; i < bloomDay.size(); i++){
            
            if(bloomDay[i] <= days){
                temp++;
            }
            else{
                temp = 0;
            }
            
            if(temp == k){
                count++;
                temp = 0;
            }
        }
        return count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        
        if(k*m > n){
            return -1;
        }
        
        int lo = 1, hi = INT_MIN;
        
        for(int i = 0; i < bloomDay.size(); i++){
            hi = max(hi, bloomDay[i]);
        }   
        
        int ans = -1;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            int c = numberofBouquets(mid,bloomDay,k);
                                     
            if(c >= m){
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
