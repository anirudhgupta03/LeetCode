//Method - 1
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<unordered_map<int,int>> dp(n);
        
        int ans = 2;
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int x = nums[i] - nums[j];
                dp[i][x] = dp[j].count(x)?dp[j][x]+1:2;  
                ans=max(dp[i][x],ans);
            }
        }
        return ans;
    }
};

//Method - 2
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<unordered_map<int,int>> v(n);
        
        vector<int> dp(n,0);
        
        int ans = 0;
        
        for(int i = 1; i < nums.size(); i++){
            for(int j = i - 1; j >= 0; j--){
                
                int diff = nums[i] - nums[j];
                
                if(v[i][diff] == 0){
                    if(v[j][diff] == 0){
                        dp[i] = max(dp[i], 2);
                        v[i][diff] = 2;
                    }
                    else{
                        dp[i] = max(dp[i], v[j][diff] + 1);
                        v[i][diff] = v[j][diff] + 1;
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

//Method - 3
//Using the constraints
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1001,0));
       
        int len = 0; 
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int diff = nums[i] - nums[j] + 500;
                if(dp[j][diff]){
                    dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                }
                else{
                    dp[i][diff] = max(dp[i][diff], 2);
                }
                len = max(len, dp[i][diff]);
            }
        }
        return len;
    }
};

//Method - 4
//Best
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        
        int N=A.size();
        
        if(N < 3) return N;
        
        vector<vector<int> > dp(N, vector<int>(N, -1));
        
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                dp[i][j]=2;
            }
        }
        
        unordered_map<int,int> umap;
        umap[A[0]]=0;
        
        for(int i = 1; i < N; i++){
            for(int j = i + 1; j < N; j++){
                int ele= 2*A[i]-A[j];
                if(umap.find(ele)== umap.end()){
                    dp[i][j]= max(dp[i][j] , 2);
                }
                else{
                    int pos= umap[ele];
                    dp[i][j]= max(dp[i][j] , dp[pos][i]+1);
                }
            }
            umap[A[i]]=i;
        }
        int maxi=2;
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                maxi= max(maxi , dp[i][j]);
            }
        }
        return maxi;
    }
};
