//Ref: https://www.youtube.com/watch?v=WJAA6jr8hMM
class Solution {
public:
    int reachNumber(int target) {
        
        target = abs(target);
        int sum = 0, steps = 0;
        
        if(target == 0){
            return 0;
        }
        
        while(sum < target){
            sum += steps;
            steps++;
        }
        
        while((sum - target) % 2 == 1){
            sum += steps;
            steps++;
        }
        return steps - 1; 
    }
};
