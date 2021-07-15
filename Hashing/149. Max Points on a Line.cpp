class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        double inf = 1e9 + 7;
        
        int maxPoints = 1;
        
        for(int i = 0; i < points.size(); i++){
            
            unordered_map<double,int> umap;
            
            for(int j = i + 1; j < points.size(); j++){
                
                int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                
                double slope;
                
                if(x2 - x1 == 0){
                    slope = inf;
                }
                else{
                    slope = (double)(y2 - y1)/(x2 - x1);
                }
                
                if(umap.find(slope) == umap.end()){
                    umap[slope] = 2;
                }
                else{
                    umap[slope]++;
                }
                maxPoints = max(maxPoints,umap[slope]);
            }
        }
        
        return maxPoints;
    }
};
