class Solution {
public:
    #define vvi vector<vector<int>>
    #define pii pair<int,int>
    #define pvpii pair<vvi,pii>
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int slidingPuzzle(vector<vector<int>>& board) {
        
        vector<vector<int>> dest(2, vector<int>(3, 0));
        int count = 1;
        
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                dest[i][j] = count;
                count++;
            }
        }
        dest[1][2] = 0;
        pii pos;
        
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == 0){
                    pos = {i, j};
                    break;
                }
            }
        }
        queue<pvpii> q;
        q.push({board, pos});
        
        set<vvi> vis;
        
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                pvpii p = q.front();
                q.pop();
                
                vector<vector<int>> temp = p.first;
                pos = p.second;
                
                if(temp == dest){
                    return level;
                }
                if(vis.find(temp) != vis.end()) continue;
                vis.insert(temp);
                
                int x = pos.first, y = pos.second;
                for(int i = 0; i < 4; i++){
                    int xo = x + dx[i], yo = y + dy[i];
                    if(xo >= 0 && yo >= 0 && xo < 2 && yo < 3){
                        swap(temp[xo][yo], temp[x][y]);
                        if(vis.find(temp) == vis.end()){
                            q.push({temp,{xo,yo}});
                        }
                        swap(temp[xo][yo], temp[x][y]);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
