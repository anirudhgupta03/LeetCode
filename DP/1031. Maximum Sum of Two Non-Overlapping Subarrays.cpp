//Method - 1
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

//Optimal Approach
//Method - 2
//Ref: https://www.youtube.com/watch?v=8e6U4O5VUx0
class Solution {
public:
    int solve(int firstLen, int secondLen, int n, vector<int> &prefix, vector<int>& nums){
        
        vector<int> dp1(n,0), dp2(n,0);
        
        int sum1 = 0;
        
        for(int i = 0; i < firstLen; i++){
            sum1 += nums[i];
        }
        
        dp1[firstLen - 1] = sum1;
        
        for(int i = firstLen; i <= n - 1; i++){
            dp1[i] = max(dp1[i-1], prefix[i+1] - prefix[i-firstLen + 1]);
        }
        
        int sum2 = 0;
        
        for(int i = n - 1; i >= n - secondLen; i--){
            sum2 += nums[i];
        }
        
        dp2[n - secondLen] = sum2;
        
        for(int i = n - secondLen - 1; i >= 0; i--){
            dp2[i] = max(dp2[i+1], prefix[i + secondLen] - prefix[i]);
        }
        
        int maxsum = INT_MIN;
        
        for(int i = 0; i < n; i++){
            cout << dp1[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; i++){
            cout << dp2[i] << " ";
        }
        cout << endl;
        for(int i = firstLen - 1; i <= n - secondLen - 1; i++){
            maxsum = max(maxsum, dp1[i] + dp2[i+1]);
        }
        return maxsum;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        
        int n = nums.size();
        
        vector<int> prefix(n+1,0);
        
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        int maxsum = 0;
        
        maxsum = max(maxsum, solve(firstLen, secondLen, n, prefix, nums));
        
        swap(firstLen, secondLen);
        
        maxsum = max(maxsum, solve(firstLen, secondLen, n, prefix, nums));
        
        return maxsum;
    }
};

//Method - 3
class Solution {
public:
    int solve(vector<int>& nums, int firstLen, int secondLen){
        
        int n = nums.size();
        int sum = 0;
        
        for(int i = 0; i < firstLen; i++){
            sum += nums[i];
        }
        
        vector<int> dp1(n, 0);
        dp1[firstLen - 1] = sum;
        
        for(int i = firstLen; i < n; i++){
            sum += nums[i];
            sum -= nums[i - firstLen];
            dp1[i] = max(dp1[i - 1], sum);
        }
        
        sum = 0;
        for(int i = n - 1; i >= n - secondLen; i--){
            sum += nums[i];
        }
        vector<int> dp2(n, 0);
        dp2[n - secondLen] = sum;
        
        for(int i = n - secondLen - 1; i >= 0; i--){
            sum += nums[i];
            sum -= nums[i + secondLen];
            dp2[i] = max(dp2[i + 1], sum);
        }
        
        int maxSum = 0;
        for(int i = firstLen - 1; i < n - secondLen; i++){
            maxSum = max(maxSum, dp1[i] + dp2[i + 1]);
        }
        return maxSum;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        
        return max(solve(nums, firstLen, secondLen), solve(nums, secondLen, firstLen));
    }
};
