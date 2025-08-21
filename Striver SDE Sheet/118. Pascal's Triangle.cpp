//Method - 1
//TC: O(N*N)
//SC: O(2*N)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res;
        vector<int> pre = {1};
        res.push_back(pre);

        for(int i = 2; i <= numRows; i++){
            vector<int> curr;
            curr.push_back(1);
            for(int j = 1; j <= pre.size() - 1; j++){
                curr.push_back(pre[j - 1] + pre[j]);
            }
            curr.push_back(1);
            pre = curr;
            res.push_back(pre);
        }
        return res;
    }
};

//Method - 2
//TC: O(N*N)
//SC: O(N)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res;
        res.push_back({1});

        for(int i = 2; i <= numRows; i++){
            vector<int> curr;
            int pVal = 1;
            curr.push_back(pVal);
            for(int j = 1; j <= i - 1; j++){
                pVal = (pVal*(i - j));
                pVal /= j;
                curr.push_back(pVal);
            }
            res.push_back(curr);
        }
        return res;
    }
};
