//Disjoint Set Union-Find
//Ref: https://www.youtube.com/watch?v=ZJFP49Tholc
//Method - 1
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

//Method - 2
class Solution {
public:
    #define pii pair<int,int>
    int findP(int node, vector<int> &par){
        if(par[node] == -1){
            return node;
        }
        return par[node] = findP(par[node], par);
    }
    int findLatestStep(vector<int>& arr, int m) {
        
        int n = arr.size();
        
        vector<int> par(n, -1), size(n, 0), v(n, 0);
        
        int ans = -1, count = 0, lpar, rpar, lsize, rsize, ind, tsize;
        bool flag;
        
        for(int i = 0; i < n; i++){ 
            
            ind = arr[i] - 1;
            flag = false;
            tsize = 0;
            v[ind] = 1;
            
            if(ind + 1 < n && v[ind + 1]){
                rpar = findP(ind + 1, par);
                rsize = size[rpar];
                tsize = rsize + 1;
                if(rsize == m) count--;
                par[rpar] = ind;
                size[ind]= tsize;
                flag = true;
            }
            
            if(ind - 1 >= 0 && v[ind - 1]){
                lpar = findP(ind - 1, par);
                lsize = size[lpar];
                tsize += lsize;
                if(!flag) tsize++;
                if(lsize == m) count--;
                par[ind] = lpar;
                size[lpar] = tsize;
                flag = true;
            }
            
            if(!flag){
                size[ind] = 1;
                tsize = 1;
            }
            
            if(tsize == m) count++;
            if(count) ans = i + 1;
        }
        return ans;
    }
};
