//Method - 1
//Ref: https://www.youtube.com/watch?v=D_0QMx9GXjg&ab_channel=BroCoders
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        vector<vector<int>> v;
        
        for(int i = 0; i < ranges.size(); i++){
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            v.push_back({left, right});
        }
        
        sort(v.begin(), v.end());
        
        int start = 0, i = 0, ans = 0;
        
        while(start < n){
            int maxa = INT_MIN;
            while(i < v.size() && v[i][0] <= start){
                maxa = max(maxa, v[i][1]);
                i++;
            }
            if(maxa < start){
                return -1;
            }
            ans++;
            start = maxa;
        }
        return ans;
    }
};

//Method - 2
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        vector<int> dp(n + 1, -1);
        
        for(int i = 0; i < ranges.size(); i++){
            int l = max(0, i - ranges[i]);
            int r = min(n, i + ranges[i]);
            for(int j = l; j <= r; j++){
                dp[j] = max(dp[j], r);
            }
        }
    
        int ind = 0, count = 0;    
        while(ind != n){
            if(ind == dp[ind]){
                return -1;
            }
            ind = dp[ind];
            count++;
        }
        return count;
    }
};
