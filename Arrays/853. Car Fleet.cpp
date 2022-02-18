//Ref: https://www.youtube.com/watch?v=-KsJrT77MJk
class Solution {
public:
    #define pid pair<int,double>
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = speed.size();
        if(n == 0){
            return 0;
        }
        vector<pid> car(n);
        
        for(int i = 0; i < n; i++){
            car[i] = {position[i], (double)(target - position[i])/speed[i]};
        }
        sort(car.begin(), car.end());
        
        int count = 0;
        for(int i = n - 1; i >= 1; i--){
            
            if(car[i].second >= car[i - 1].second){
                car[i - 1] = car[i];
            }
            else{
                count++;
            }
        }
        count++;
        return count;
    }
};
