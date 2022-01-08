//Disjoint Set Union-Find
//Ref: https://www.youtube.com/watch?v=ZJFP49Tholc
class Solution {
public:
    int find(int x, vector<int> &par){
        
        if(par[x] == x){
            return x;
        }
        return par[x] = find(par[x], par);
    }
    void merge(int x, int y, vector<int> &par, vector<int> &cnt, vector<int> &sz){
        
        x = find(x, par);
        y = find(y, par);
        
        if(x != y){
            cnt[sz[x]]--;
            cnt[sz[y]]--;
            par[x] = y;
            sz[y] += sz[x];
            cnt[sz[y]]++;
        }
    }
    int findLatestStep(vector<int>& arr, int m) {
        
        int n = arr.size();
        
        vector<int> par(n + 2), sz(n + 2), temp(n + 2), cnt(n + 2, 0);
        
        for(int i = 1; i <= n; i++){
            par[i] = i;
            sz[i] = 1;
        }
        
        int seen = -1, step = 1;
        
        for(auto i: arr){
            temp[i] = 1;
            cnt[1]++;
            
            if(temp[i-1]){
                merge(i, i - 1, par, cnt, sz);
            }
            if(temp[i+1]){
                merge(i, i + 1, par, cnt, sz);
            }
            if(cnt[m]) seen = step;
            step++;
        }
        return seen;
    }
};
