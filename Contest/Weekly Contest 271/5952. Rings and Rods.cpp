class Solution {
public:
    #define pipii pair<int,pair<int,int>>
    
    int countPoints(string rings) {
        
        unordered_map<int,pipii> umap;
        
        for(int i = 0; i < rings.size() - 1; i++){
            if(rings[i] == 'R') umap[rings[i+1]-'0'].first++;
            else if(rings[i] == 'B') umap[rings[i+1]-'0'].second.first++;
            else if(rings[i] == 'G') umap[rings[i+1]-'0'].second.second++;
        }
        
        int count = 0;
        
        for(auto x: umap){
            
            int r = x.second.first, b = x.second.second.first, g = x.second.second.second;
            if(r >= 1 && b >= 1 && g >= 1) count++;
        }
        return count;
    }
};
