class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int> count(n, 0);
        vector<vector<int>> adj(n, vector<int>(n, 0));
        
        for(int i = 0; i < roads.size(); i++){
            int a = roads[i][0], b = roads[i][1];
            count[a]++;
            count[b]++;
            adj[a][b] = 1;
            adj[b][a] = 1;
        }
        
        int maxRank = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int currRank = count[i] + count[j] - adj[i][j];
                maxRank = max(maxRank, currRank);
            }
        }
        return maxRank;
    }
};
