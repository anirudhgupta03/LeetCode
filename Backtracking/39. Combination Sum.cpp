class Solution {
public:

    void solve(vector<int> &A,vector<int> &v, int B, int ind,vector<vector<int>> &vec){
        
        if(ind == A.size()){
            if(B == 0){
                vec.push_back(v);
            }
            return;
        }
        else if(B == 0){
            vec.push_back(v);
            return;
        }

        if(A[ind] <= B){
            solve(A,v,B,ind+1,vec);
            v.push_back(A[ind]);
            solve(A,v,B-A[ind],ind,vec);
            v.pop_back();
        }
        else{
            solve(A,v,B,ind+1,vec);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        
        vector<int> v;

        vector<vector<int>> vec;

        int ind = 0;

        solve(candidates,v,target,ind,vec);

        return vec;
    }
};
