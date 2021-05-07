class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        
        int tempdist = INT_MAX, ind = -1;
        
        for(int i = 0; i < points.size(); i++){
            
            int xo = points[i][0], yo = points[i][1];
            
            if(x == xo || y == yo){
                
                if(abs(x-xo) + abs(y-yo) < tempdist){
                    ind = i;
                    tempdist = abs(x-xo) + abs(y-yo);
                }
            }
        }
        
        return ind;
    }
};
