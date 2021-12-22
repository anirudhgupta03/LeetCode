class Solution {
public:
    #define pvii pair<vector<int>,int>
    #define ll long long
    pair<vector<int>,int> solve(int ind, int count, vector<ll> &prefix, int n, vector<vector<pvii>> &dp, int firstLen, int secondLen, bool &flag1, bool &flag2){
        
        if(count == 2){
            vector<int> res;
            return dp[ind][count] = {res,0};
        }
        
        vector<int> temp1 = dp[ind][count].first;
        int temp2 = dp[ind][count].second;
        
        // if(temp1.size() != 0 && temp2 != INT_MIN){     //On applying this 49/51 tc were passing
        //     return {temp1, temp2};
        // }
        
        vector<int> res;
        int maxsum = INT_MIN;
        
        for(int i = ind; i < n; i++){
            
            if(count == 0){
                
                if(i <= n - (firstLen + secondLen)){
                    flag1 = true;
                    pvii p = solve(i + firstLen, count + 1, prefix, n, dp, firstLen, secondLen, flag1, flag2);

                    if(prefix[i+firstLen] - prefix[i] + p.second > maxsum){
                        vector<int> vec = p.first;
                        maxsum = prefix[i+firstLen] - prefix[i] + p.second;
                        vec.push_back(i);
                        res = vec;
                    }   
                    flag1 = false;
                }
                
                if(i <= n - (firstLen + secondLen)){
                    flag2 = true;
                    pvii p = solve(i + secondLen, count + 1, prefix, n, dp, firstLen, secondLen, flag1, flag2);
                
                    if(prefix[i+secondLen] - prefix[i] + p.second > maxsum){
                        vector<int> vec = p.first;
                        maxsum = prefix[i+secondLen] - prefix[i] + p.second;
                        vec.push_back(i);
                        res = vec;
                    }
                    flag2 = false;
                }
            }
            else if(count == 1){
                
                if(!flag1){
                    if(i <= n - firstLen){
                        flag1 = true;
                        pvii p = solve(i + firstLen, count + 1, prefix, n, dp, firstLen, secondLen, flag1, flag2);

                        if(prefix[i+firstLen] - prefix[i] + p.second > maxsum){
                            vector<int> vec = p.first;
                            maxsum = prefix[i+firstLen] - prefix[i] + p.second;
                            vec.push_back(i);
                            res = vec;
                        }   
                        flag1 = false;
                    }
                }
                else if(!flag2){
                    if(i <= n - secondLen){
                        flag2 = true;
                        pvii p = solve(i + secondLen, count + 1, prefix, n, dp, firstLen, secondLen, flag1, flag2);

                        if(prefix[i+secondLen] - prefix[i] + p.second > maxsum){
                            vector<int> vec = p.first;
                            maxsum = prefix[i+secondLen] - prefix[i] + p.second;
                            vec.push_back(i);
                            res = vec;
                        }
                        flag2 = false;
                    }
                }
            }
        }
        return dp[ind][count] = {res, maxsum};
    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        
        int n = nums.size();
        
        vector<int> res, temp;
        
        vector<ll> prefix(n+1,0);
        
        prefix[0] = 0;
        
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        
        vector<vector<pvii>> dp(n+1, vector<pvii>(3,{temp,INT_MIN}));
        
        int ans;
        bool flag1 = false, flag2 = false;
        
        pvii p = solve(0, 0, prefix, n, dp, firstLen, secondLen, flag1, flag2);
        res = p.first;
        for(int i = 0; i < res.size(); i++){
            if(res[i] < 0)
            cout << res[i] << " ";
        }
        cout << endl;
        return p.second;
    }
};
