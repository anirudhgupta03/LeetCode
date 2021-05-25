class Solution {
public:
    bool static cmp(pair<int,int> p1, pair<int,int> p2){
        
        if(p1.second == p2.second){
            return p1.first > p2.first;
        }
        
        return p1.second > p2.second;
    }
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        
        vector<pair<int,int>> v;
        
        if(veganFriendly == 0){
            for(int i = 0; i < restaurants.size(); i++){
                    if(restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance){
                        v.push_back({restaurants[i][0],restaurants[i][1]});
                    }
            }
        }
        else{
            for(int i = 0; i < restaurants.size(); i++){
                    if(restaurants[i][2] == 1 && restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance){
                        v.push_back({restaurants[i][0],restaurants[i][1]});
                    }
            }
        }
        
        sort(v.begin(),v.end(),cmp);
        
        vector<int> res;
        
        for(int i = 0; i < v.size(); i++){
            res.push_back(v[i].first);
        }
        
        return res;
    }
};
