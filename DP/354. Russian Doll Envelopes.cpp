//Method - 1
//TLE
//LIS
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n = envelopes.size();
        
        if(n == 0){
            return 0;
        }
        
        sort(envelopes.begin(),envelopes.end());
        
        vector<int> dp(n+1,1);
        
        int max = 1;
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]
                  && 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                }
            }
            if(max < dp[i]){
                max = dp[i];
            }
        }
        return max;
    }
};

//Method - 2
//Ref: https://www.youtube.com/watch?v=J0WQb_SffqY
//Optimal Approach
class Solution {
public:
    bool static cmp(vector<int> &v1, vector<int> &v2){
        if(v1[0] == v2[0]){
            return v1[1] > v2[1];
        }
        return v1[0] < v2[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n = envelopes.size();
        
        if(n == 0){
            return 0;
        }
        
        sort(envelopes.begin(),envelopes.end(), cmp);
        
        vector<int> v;
        v.push_back(envelopes[0][1]);
        
        int length = 1;
        
        for(int i = 1; i < envelopes.size(); i++){
           
            auto itr = lower_bound(v.begin(), v.end(), envelopes[i][1]);
            
            if(itr == v.end()){
                length++;
                v.push_back(envelopes[i][1]);
            }
            else{
                *itr = envelopes[i][1];
            }
        }
        return length;
    }
};
