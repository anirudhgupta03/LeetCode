//Method - 1
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    #define ll long long
    int firstBadVersion(int n) {
        
        ll lo = 1, hi = n;
        
        int ans;
        
        while(lo <= hi){
            
            ll mid = (lo + hi)/2;
            
            if(isBadVersion(mid)){
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

//Method - 2
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int lo = 1, hi = n, ans;
        
        while(lo <= hi){
            
            int mid = lo + (hi - lo)/2;
            
            if(isBadVersion(mid)){
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
