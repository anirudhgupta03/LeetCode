class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        vector<int> vis(n, 0);
        vis[0] = 1;
        queue<int> q;
        
        for(int i = 0; i < rooms[0].size(); i++){
            q.push(rooms[0][i]);
        }
        
        while(!q.empty()){
            int key = q.front();
            q.pop();
            
            if(vis[key]) continue;
           
            vis[key] = 1;
          
            for(int i = 0; i < rooms[key].size(); i++){
                if(!vis[rooms[key][i]]){
                    q.push(rooms[key][i]);
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};
