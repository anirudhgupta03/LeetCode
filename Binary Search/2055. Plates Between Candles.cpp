//Method - 1
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        
        int n = s.size();
        
        vector<int> candles;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '|'){
                candles.push_back(i);
            }
        }
        
        for(int i = 0; i < candles.size(); i++){
            cout << candles[i] << " ";
        }
        cout << endl;
        
        vector<int> temp(candles.size(), 0);
        int ind = 0, count = 0;
        bool flag = false;

        for(int i = 1; i <= n; i++){
            if(s[i - 1] == '*'){
                count++;
            }
            else if(s[i - 1] == '|' && !flag){
                flag = true;
                count = 0;
                ind++;
            }
            else if(s[i - 1] == '|' && flag){
                temp[ind] = count;
                ind++;
            }
        }
        
        for(int i = 0; i < candles.size(); i++){
            cout << temp[i] << " ";
        }
        cout << endl;
        vector<int> res(queries.size(), 0);
        
        for(int i = 0; i < queries.size(); i++){
            
            int left = queries[i][0], right = queries[i][1];
            
            int lo = 0, hi = candles.size() - 1;
            
            int leftcandle = -1, rightcandle = -1;
            
            while(lo <= hi){
                int mid = (lo + hi)/2;
                
                if(candles[mid] >= left){
                    leftcandle = mid;
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }
            
            lo = 0, hi = candles.size() - 1;
                
            while(lo <= hi){
                int mid = (lo + hi)/2;
                
                if(candles[mid] <= right){
                    rightcandle = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            
            if(leftcandle < rightcandle && leftcandle != -1 && rightcandle != -1){
                res[i] = temp[rightcandle] - temp[leftcandle];
            }
        }
        return res;
    }
};

//Method - 2
//Ref: https://www.youtube.com/watch?v=G0Sy71_lBAw
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        
        int n = s.size();
        
        vector<int> prefix(n + 1, 0);
        
        for(int i = 1; i <= n; i++){
            if(s[i - 1] == '*'){
                prefix[i] = prefix[i - 1] + 1;
            }
            else{
                prefix[i] = prefix[i - 1];
            }
        }
        
        vector<int> nearestCandleToLeft(n), nearestCandleToRight(n);
        
        int ind = -1;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '|'){
                ind = i;
            }
            nearestCandleToLeft[i] = ind;
        }
        
        ind = -1;
        
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '|'){
                ind = i;
            }
            nearestCandleToRight[i] = ind;
        }
        vector<int> res(queries.size());
        
        for(int i = 0; i < queries.size(); i++){
            
            int s = queries[i][0], e = queries[i][1];
            
            int r = nearestCandleToRight[s];
            int l = nearestCandleToLeft[e];
            
            if(l != -1 && r != -1 && l >= r && l <= e && r >= s){
                res[i] = prefix[l + 1] - prefix[r];
            }
            else{
                res[i] = 0;
            }
        }
        return res;
    }
};
