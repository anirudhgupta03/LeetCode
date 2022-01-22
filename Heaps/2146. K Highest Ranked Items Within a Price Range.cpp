class Solution {
public:
    #define ppiipii pair<pair<int,int>,pair<int,int>>
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    struct cmp{
        bool operator()(ppiipii &p1, ppiipii &p2){
            if(p1.first.first == p2.first.first){
                if(p1.first.second == p2.first.second){
                    if(p1.second.first == p2.second.first){
                        return p1.second.second > p2.second.second;
                    }
                    return p1.second.first > p2.second.first;
                }
                return p1.first.second > p2.first.second;
            }
            return p1.first.first > p2.first.first;
        }
    };
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        
        priority_queue<ppiipii,vector<ppiipii>,cmp> pq;
        
        int sx = start[0], sy = start[1];
        
        pq.push({{0,grid[sx][sy]},{sx,sy}});
            
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        int count = 0;
        
        vector<vector<int>> res;
        
        while(!pq.empty()){
            
            ppiipii p = pq.top();
            pq.pop();
            
            int td = p.first.first, tp = p.first.second;
            int tx = p.second.first, ty = p.second.second;
            
            if(vis[tx][ty]){
                continue;
            }
            vis[tx][ty] = 1;
            
            if(tp >= pricing[0] && tp <= pricing[1]){
                vector<int> v = {tx,ty};
                count++;
                res.push_back(v);
            }
            
            if(count == k){
                break;
            }
            for(int i = 0; i < 4; i++){
                int txo = tx + dx[i], tyo = ty + dy[i];
                if(txo >= 0 && tyo >= 0 && txo < m && tyo < n){
                    if(grid[txo][tyo] != 0 && vis[txo][tyo] == 0){
                        pq.push({{td + 1, grid[txo][tyo]},{txo,tyo}});
                    }
                }
            }
        }
        return res;
    }
};
