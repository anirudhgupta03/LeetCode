//Ref: https://www.youtube.com/watch?v=TXAuxeYBTdg&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=13
//Excellent Question
//Method - 1
class Solution {
public:
    bool isPossible(int day, vector<int> &bloomDay, int m, int k){
        int count = 0;
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

//Method - 2
//Optimal Method 
#define ll long long
class Solution {
public:
    bool isPossibleToMakeMBouquets(int day, vector<int>& bloomDay, int m, int k){
        int ans = 0, count = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                count++;
            }
            else{
                count = 0;
            }
            if(count == k){
                count = 0;
                ans++;
            }
        }
        return ans >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((ll)m*k > bloomDay.size()){
            return -1;
        }
        int lo = INT_MAX, hi = INT_MIN;
        for(int &day: bloomDay){
            lo = min(lo, day);
            hi = max(hi, day);
        }
        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(isPossibleToMakeMBouquets(mid, bloomDay, m, k)){
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
