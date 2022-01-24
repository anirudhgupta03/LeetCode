//Ref: https://www.youtube.com/watch?v=_fQQjh7lMBI
class Solution {
public:
    int convert(int mask, vector<int> &roles){
        
        int count = 0;
        for(int i = roles.size() - 1; i >= 0; i--){
            roles[i] = mask%2;
            if(roles[i] == 1) count++;
            mask /= 2;
        }
        return count;
    }
    bool isValid(vector<vector<int>> &statements, vector<int> &roles){
        
        int n = roles.size();
        
        for(int i = 0; i < n; i++){
            if(roles[i]){
                for(int j = 0; j < statements[i].size(); j++){
                    if(statements[i][j] != 2){
                        if(roles[j] != statements[i][j]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    int maximumGood(vector<vector<int>>& statements) {
        
        int n = statements.size();
        int ans = 0;
        
        vector<int> roles(n);
        
        for(int i = 1; i < 1 << n; i++){
            int currentGood = convert(i, roles);
            if(isValid(statements, roles)){
                ans = max(ans, currentGood);
            }
        }
        return ans;
    }
};
