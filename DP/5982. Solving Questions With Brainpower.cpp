class Solution {
public:
    #define ll long long
    long long mostPoints(vector<vector<int>>& questions) {
        
        int n = questions.size();
        vector<ll> temp(n, 0);
        
        temp[n - 1] = questions[n - 1][0];
        
        for(int i = n - 2; i >= 0; i--){
            if(i + questions[i][1] + 1 <= n - 1)
                temp[i] = max(temp[i + 1], (ll)questions[i][0] + temp[min(n - 1, i + questions[i][1] + 1)]);
            else
                temp[i] = max(temp[i + 1], (ll)questions[i][0]);
        }
        return temp[0];
    }
};
