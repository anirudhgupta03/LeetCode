//Ref: https://www.youtube.com/watch?v=pYs3qj42h3c
class Solution {
public:
    map<pair<int,int>,pair<int,int>> dp;
    pair<int,int> solve(int st, int end, vector<int> &arr){
        
        if(st == end){
            return {arr[st],0};
        }
        if(dp.find({st,end}) != dp.end()){
            return dp[{st,end}];
        }
        int minSum = INT_MAX;
        int maxLeaf = INT_MIN;
        for(int i = st; i < end; i++){
            pair<int,int> left = solve(st,i,arr);
            pair<int,int> right = solve(i + 1, end, arr);
            maxLeaf = max(left.first, right.first);
            minSum = min(minSum, left.second + right.second + left.first*right.first);
        }
        return dp[{st,end}] = {maxLeaf, minSum};
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        dp.clear();
        return solve(0, arr.size() - 1, arr).second;
    }
};
