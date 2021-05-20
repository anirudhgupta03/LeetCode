class Solution {
public:
    bool static cmp(pair<string,int> p1, pair<string,int> p2){
        if(p1.second == p2.second){
            return p1.first < p2.first;
        }
        return p1.second < p2.second;
    }
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        
        
        int n = friends.size();
        
        vector<int> al[n];
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < friends[i].size(); j++){
                al[i].push_back(friends[i][j]);
            }
        }
        
        vector<int> dist(n,-1);
        
        vector<int> vis(n,0);
        
        dist[id] = 0;
        vis[id] = 1;
        
        queue<int> q;
        
        q.push(id);
        
        while(!q.empty()){
            
            int curr = q.front();
            
            q.pop();
            
            for(int i = 0; i < al[curr].size(); i++){
                
                int child = al[curr][i];
                
                if(vis[child] == 0){
                    dist[child] = dist[curr] + 1;
                    vis[child] = 1;
                    q.push(child);
                }
            }
        }
        
        map<string,int> m;
        
        for(int i = 0; i < n; i++){
            
            if(dist[i] == level){
                for(int j = 0; j < watchedVideos[i].size(); j++){
                    m[watchedVideos[i][j]]++;
                }
            }
        }
        
        vector<pair<string,int>> v1;
        
        map<string,int> :: iterator it;
        
        for(it = m.begin(); it != m.end(); it++){
            v1.push_back({it->first,it->second});
        }
        
        sort(v1.begin(),v1.end(),cmp);
        
        vector<string> ans;
        
        for(int i = 0; i < v1.size(); i++){
            ans.push_back(v1[i].first);
        }
        return ans;
    }
};
