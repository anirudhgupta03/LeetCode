//https://www.codingninjas.com/codestudio/problems/count-derangements_873861?topList=top-amazon-coding-interview-questions&leftPanelTab=1
#define ll long long
long long int countDerangements(int n) {
   	if(n == 1){
        return 0;
    }
    
    ll dp[n+1];
    dp[1] = 0;
    dp[2] = 1;
    
    int mod = 1e9 + 7;
    
    for(int i = 3; i <= n; i++){
        dp[i] = ((i - 1)*((dp[i-1] + dp[i-2]))%mod)%mod;
    }
    return dp[n];
}
