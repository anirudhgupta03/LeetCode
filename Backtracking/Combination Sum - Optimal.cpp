/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Combination Sum.
Memory Usage: 10.7 MB, less than 84.38% of C++ online submissions for Combination Sum.
*/
//Since all the elements are distinct so no need to use set
class Solution {
public:
    
    void solve(int ind, vector<int> &A, int B, vector<vector<int>> &res, vector<int> &ans){
    
        if(ind == A.size()){
            return;
        }
        if(B == 0){
            res.push_back(ans);
            return;
        }

        if(A[ind] <= B){
            ans.push_back(A[ind]);
            solve(ind,A,B - A[ind],res,ans);
            ans.pop_back();
            solve(ind+1,A,B,res,ans);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& A, int B) {
        
        sort(A.begin(),A.end());
    
        vector<vector<int>> res;
        vector<int> ans;

        solve(0,A,B,res,ans);

        return res;
    }
};
