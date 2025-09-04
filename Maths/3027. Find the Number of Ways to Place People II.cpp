class Solution {
public:
    bool static cmp(vector<int> &point1, vector<int> &point2){
        if(point1[0] == point2[0]){
            return point1[1] > point2[1];
        }
        return point1[0] < point2[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        
        int n = points.size();
        sort(points.begin(), points.end(), cmp);

        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int maxH = INT_MIN;
            for(int j = i + 1; j < n; j++){
                if(points[j][1] <= points[i][1]){
                    if(points[j][1] > maxH){
                        ans++;
                        maxH = points[j][1];
                    }
                }
            }
        }
        return ans;
    }
};
