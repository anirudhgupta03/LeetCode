class Solution {
public:
    #define ll long long
    long long minimumPerimeter(long long neededApples) {
    
        ll sum = 0, length = 0;
        
        while(sum < neededApples){
            length++;
            sum += 12*(length*length);
        }

        return 8*length;
    }
};
