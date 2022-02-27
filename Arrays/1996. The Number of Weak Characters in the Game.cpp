//Ref: https://www.youtube.com/watch?v=3MOo5Vpskj0
class Solution {
public:
    bool static cmp(vector<int> &v1, vector<int> &v2){
        if(v1[0] == v2[0]){
            return v1[1] > v2[1];
        }
        return v1[0] < v2[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        sort(properties.begin(), properties.end(), cmp);
        
        int maxDefence = 0, count = 0;
        
        for(int i = properties.size() - 1; i >= 0; i--){
            maxDefence = max(maxDefence, properties[i][1]);
            if(properties[i][1] < maxDefence) count++;
        }
        return count;
    }
};
