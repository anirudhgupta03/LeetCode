class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
       
        map<int,int> year;
        
        for(int i = 0; i < logs.size(); i++){
            
            int birth = logs[i][0], death = logs[i][1];
            
            for(int j = birth; j <= death - 1; j++){
                year[j]++;
            }
        }
        
        map<int,int> :: iterator it;
        
        int ans, people = INT_MIN;
        
        for(it = year.begin(); it != year.end(); it++){
            
            if(it->second > people){
                ans = it->first;
                people = it->second;
            }
        }
        
        return ans;
    }
};
