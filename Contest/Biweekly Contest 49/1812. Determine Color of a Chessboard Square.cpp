class Solution {
public:
    bool squareIsWhite(string coordinates) {
        
        int col = coordinates[1] - 96;
        int row = coordinates[0] - 48;
        
        if(col % 2 == 0 && row % 2 != 0 || col % 2 != 0 & row % 2 == 0){
            return true;
        }
        
        return false;
    }
};
