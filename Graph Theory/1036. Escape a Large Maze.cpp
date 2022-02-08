//Ref: https://www.youtube.com/watch?v=bZqIfxD902c
class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    #define n 1e6
    bool search(vector<int>& source, vector<int>& target, set<pair<int,int>> vis, int blockcnt){
        
        queue<pair<int,int>> q;
        q.push({source[0], source[1]});
        
        while(!q.empty()){
            if(blockcnt == 0){
                return true;
            }
            int sz = q.size();
            while(sz--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                
                if(x == target[0] && y == target[1]){
                    return true;
                }
                
                if(vis.find({x, y}) != vis.end()) continue;
                vis.insert({x,y});
                
                for(int i = 0; i < 4; i++){
                    int xo = x + dx[i], yo = y + dy[i];
                    if(xo >= 0 && yo >= 0 && xo < n && yo < n){
                        if(vis.find({xo, yo}) == vis.end()){
                            q.push({xo,yo});
                        }
                    }
                }
            }
            blockcnt--;
        }
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        
        set<pair<int,int>> block;
        int blockcnt = 0;
        
        for(auto x: blocked){
            block.insert({x[0],x[1]});
            blockcnt++;
        }
        return search(source, target, block, blockcnt) && search(target, source, block, blockcnt);
    }
};
