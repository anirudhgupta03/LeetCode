class Solution {
public:
    
    void solve(int ind, vector<int> &A, int B, vector<int> &v, set<vector<int>> &res){
    
        if(B == 0){
            res.insert(v);
            return;
        }
        if(ind == A.size()){
            return;
        }

        if(A[ind] <= B){
            v.push_back(A[ind]);
            solve(ind+1,A,B-A[ind],v,res);
            v.pop_back();
            solve(ind+1,A,B,v,res);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& A, int B) {
        
        sort(A.begin(),A.end());
    
        set<vector<int>> res;
        vector<int> v;

        solve(0,A,B,v,res);

        vector<vector<int>> ans;

        set<vector<int>> :: iterator it;

        for(it = res.begin(); it!=res.end(); it++){
            ans.push_back(*it);
        }

        return ans;
    }
};
