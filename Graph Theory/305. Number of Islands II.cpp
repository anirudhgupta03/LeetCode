//Ref: https://www.youtube.com/watch?v=PcYCkgYu6uc
//https://www.lintcode.com/problem/434/?_from=collection&fromId=207
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int findp(int node, vector<int> &par){
        if(par[node] == node){
            return node;
        }
        return par[node] = findp(par[node],par);
    }
    void unionp(int node1, int node2, vector<int> &par){
        par[node2] = node1;
    }
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        
        vector<int> par(n*m);

        for(int i = 0; i < n*m; i++){
            par[i] = i;
        }

        vector<int> res;
        int count = 0;

        vector<vector<int>> grid(n, vector<int>(m, 0));

        for(int i = 0; i < operators.size(); i++){
            int u = operators[i].x, v = operators[i].y;

            if(grid[u][v] == 1){
                res.push_back(count);
                continue;
            }

            grid[u][v] = 1;
            int cell = m*u + v;
            int parcell = findp(cell, par);
            count++;

            for(int j = 0; j < 4; j++){
                int io = u + dx[j], jo = v + dy[j];
                if(io >= 0 && jo >= 0 && io < n && jo < m && grid[io][jo]){
                    int cello = m*io + jo;
                    int parcello = findp(cello, par);

                    if(parcell != parcello){
                        count--;
                        unionp(parcell, parcello, par);
                    } 
                }
            }
            res.push_back(count);
        }
        return res;
    }
};
