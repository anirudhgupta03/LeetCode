//Ref: https://www.lintcode.com/problem/866/
class Solution {
public:
    /**
     * @param A: a list of integer
     * @param B: an integer
     * @return: return a list of integer
     */
    #define pivi pair<int,vector<int>>
    pair<int,vector<int>> solve(int ind, vector<int> &A, int B, map<int,pivi> &dp){

        if(ind == A.size()){
            vector<int> path = {ind};
            return {A[A.size()-1], path};
        }

        if(dp.find(ind) != dp.end()){
            return dp[ind];
        } 
        int mincost = INT_MAX;
        vector<int> path;

        for(int i = ind + 1; i <= min((int)A.size(), ind + B); i++){
            if(A[i-1] != -1){
                pivi temp = solve(i, A, B, dp);
                if(temp.first != INT_MAX){
                    if(temp.first + A[ind-1] < mincost){
                        mincost = temp.first + A[ind-1];
                        vector<int> v = temp.second;
                        v.insert(v.begin(),ind);
                        path = v;
                    }
                    else if(temp.first + A[ind-1] == mincost){
                        vector<int> v = temp.second;
                        v.insert(v.begin(),ind);
                        if(v < path){
                            path = v;
                        }
                    }
                }
            }
        }
        return dp[ind] = {mincost, path};
    }
    vector<int> cheapestJump(vector<int> &A, int B) {
        
        int cost = 0, mincost = INT_MAX;
        vector<int> path, ans;

        if(A[0] == -1 || A[A.size() - 1] == -1){
            return ans;
        }
        map<int,pivi> dp;
        ans = solve(1, A, B, dp).second;
        return ans;
    }
};
