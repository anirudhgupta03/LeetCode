//DP + Binary Search
class Solution {
public:
    #define ppiii pair<pair<int,int>,int>
    bool static cmp(ppiii &p1, ppiii &p2){
        return p1.first.second < p2.first.second;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        vector<ppiii> v;

        int n = startTime.size();

        for(int i = 0; i < n; i++){
            v.push_back({{startTime[i], endTime[i]}, profit[i]});
        }

        sort(v.begin(), v.end(), cmp);

        vector<int> dp(n);

        for(int i = 0; i < n; i++){
            dp[i] = v[i].second;
        }

        for(int i = 1; i < n; i++){

            int lo = 0, hi = i - 1, s = v[i].first.first, ans = -1;

            while(lo <= hi){

                int mid = lo + (hi - lo)/2;

                if(s >= v[mid].first.second){
                    ans = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            dp[i] = max(dp[i], dp[i - 1]);
            if(ans != -1){
                dp[i] = max(v[i].second + dp[ans], dp[i]);
            }
        }

        return dp[n - 1];
    }
};
