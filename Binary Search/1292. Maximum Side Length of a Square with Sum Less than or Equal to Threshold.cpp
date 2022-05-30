//Ref: https://www.youtube.com/watch?v=5pXWX2okpxw

//Approach - 1
class Solution {
public:
    bool isValid(int x, int y, int m, int n){
        if(x < m && y < n){
            return true;
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        int m = mat.size(), n = mat[0].size();
        
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                prefix[i][j] = prefix[i][j-1] + mat[i-1][j-1];
            }
        }
        
        for(int j = 1; j <= n; j++){
            for(int i = 1; i <= m; i++){
                prefix[i][j] += prefix[i-1][j];
            }
        }
        
        int best = 0;
        
        int maxlen = max(m, n);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = best + 1; k <= maxlen; k++){
                    int xo = i + k - 1, yo = j + k - 1;
                    if(isValid(xo, yo, m, n)){
                        int sumOfSquare = prefix[xo + 1][yo + 1] - prefix[xo + 1][j] - prefix[i][yo + 1] + prefix[i][j];
                        if(sumOfSquare <= threshold){
                            best = max(best, k);
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return best;
    }
};

//Approach - 2
//Binary Search
class Solution {
public:
    bool isValid(int x, int y, int m, int n){
        if(x < m && y < n){
            return true;
        }
        return false;
    }
    bool squareExists(int k, vector<vector<int>> &prefix, int m, int n, int threshold){
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int xo = i + k - 1, yo = j + k - 1;
                if(isValid(xo, yo, m, n)){
                    int sumOfSquare = prefix[xo + 1][yo + 1] - prefix[xo + 1][j] - prefix[i][yo + 1] + prefix[i][j];
                    if(sumOfSquare <= threshold){
                        return true;
                    }
                }
                else{
                    break;
                }
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        int m = mat.size(), n = mat[0].size();
        
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                prefix[i][j] = prefix[i][j-1] + mat[i-1][j-1];
            }
        }
        
        for(int j = 1; j <= n; j++){
            for(int i = 1; i <= m; i++){
                prefix[i][j] += prefix[i-1][j];
            }
        }
        
        int best = 0;
        
        int maxlen = max(m, n);
        
        int lo = 1, hi = maxlen;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(squareExists(mid, prefix, m, n, threshold)){
                best = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return best;
    }
};

//Method - 3
class Solution {
public:
    bool isPossible(int len, vector<vector<int>> &mat, int threshold, vector<vector<int>> &sum){
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i <= m - len; i++){
            for(int j = len - 1; j < n; j++){
                if(sum[i + len][j + 1] - sum[i + len][j - len + 1] - (sum[i][j + 1] - sum[i][j - len + 1]) <= threshold){
                    return true;
                }
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        int m = mat.size(), n = mat[0].size();
        
        int lo = 1, hi = min(m, n);
        
        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
        
        for(int j = 1; j <= n; j++){
            for(int i = 1; i <= m; i++){
                sum[i][j] = mat[i - 1][j - 1] + sum[i - 1][j];
            }
        }
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                sum[i][j] += sum[i][j - 1];
            }
        }
        
        int ans = 0;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(isPossible(mid, mat, threshold, sum)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
};
