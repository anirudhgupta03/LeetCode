//Method - 1
class Solution {
public:
    #define ll long long
    #define mod 1000000007
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        
        int m = packages.size(), n = boxes.size();
        
        for(int i = 0; i < n; i++){
            sort(boxes[i].begin(), boxes[i].end());
        }
        
        sort(packages.begin(), packages.end());
        
        ll sum = 0;
        
        for(int i = 0; i < packages.size(); i++){
            sum = sum + packages[i];
        }
        
        ll minSpace = LLONG_MAX;
        bool flag = false;
        
        for(int i = 0; i < n; i++){
            if(boxes[i][boxes[i].size() - 1] < packages[m - 1]) continue;
            
            flag = true;
            ll lo = 0, hi = m - 1, space = 0, prev = 0;
            
            for(int j = 0; j < boxes[i].size(); j++){
                ll ans = -1;   
                while(lo <= hi){
                    ll mid = (lo + hi)/2;
                    if(boxes[i][j] >= packages[mid]){
                        ans = mid;
                        lo = mid + 1;
                    }
                    else{
                        hi = mid - 1;
                    }
                } 
                if(ans != -1){
                    space +=  boxes[i][j]*(ans - prev + 1);
                    prev = ans + 1;
                }
                lo = prev;
                hi = m - 1;
            }
            if(space < minSpace){
                minSpace = space;
            }
        }
        if(!flag) return -1;
        return (minSpace - sum)%mod;
    }
};

//Method - 2
//Ref1: https://leetcode.com/problems/minimum-space-wasted-from-packaging/discuss/1253948/Python-3-Binary-Search-%2B-pre-sum-explanation-with-picture.
//Ref2: https://leetcode.com/problems/minimum-space-wasted-from-packaging/discuss/1254116/C%2B%2BPython-Binary-Search-should-not-use-prefix-sum
class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        
        sort(packages.begin(),packages.end());
        
        long res = LONG_MAX, mod = 1e9 + 7, sum = 0;
        
        for(int i = 0; i < packages.size(); i++){
            sum += packages[i];
        }
        
        for(auto B : boxes){
            
            sort(B.begin(),B.end());
            
            if(B[B.size() - 1] < packages[packages.size() - 1]){                //If largest box size is smaller than laregest package size then not possible to pack
                continue;
            }
            
            long cur = 0, i = 0, j;
            
            for(int b : B){
                
                j = upper_bound(packages.begin(),packages.end(),b) - packages.begin();    //Find the first package with size greater than box size. Boxes on left of this found package can be packed in the box
                cur += b*(j-i);
                i = j;
            }
            
            res = min(res,cur);
        }
        
        if(res == LONG_MAX){
            return -1;
        }
        
        return (res-sum)%mod;
    }
};
