//https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/paint-house-many-colors-official/ojquestion
#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

int main()
{
  int n ;
  cin >> n ;
  int k ;
  cin >> k ;
  
  vector<vector<int>> v(n, vector<int>(k));
  
  for(int i = 0; i < n; i++){
      for(int j = 0; j < k; j++){
          cin >> v[i][j];
      }
  }
  
  vector<vector<int>> dp(k, vector<int>(n));
  
  int mine = INT_MAX, smine = INT_MAX;
  
  for(int i = 0; i < k; i++){
      dp[i][0] = v[0][i];
      if(v[0][i] < mine){
          smine = mine;
          mine = v[0][i];
      }
      else if(v[0][i] < smine){
          smine = v[0][i];
      }
  }
  
  for(int j = 1; j < n; j++){
       int tmine = INT_MAX, tsmine = INT_MAX;
       for(int i = 0; i < k; i++){
           if(mine == dp[i][j-1]){
               dp[i][j] = smine + v[j][i];
           }
           else{
               dp[i][j] = mine + v[j][i];
           }
           if(dp[i][j] < tmine){
              tsmine = tmine;
              tmine = dp[i][j];
           }
           else if(dp[i][j] < tsmine){
              tsmine = dp[i][j];
           }
       }      
       mine = tmine;
       smine = tsmine;
  }
  
  int ans = INT_MAX;
  for(int i = 0; i < k; i++){
      ans = min(ans, dp[i][n-1]);
  }
 
  cout << ans << endl;
}
