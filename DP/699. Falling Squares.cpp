//Ref: https://leetcode.com/problems/falling-squares/discuss/108766/Easy-Understood-O(n2)-Solution-with-explanation
class Solution {
public:
    int getMaxHeight(vector<vector<int>>& prev, vector<int> &temp){
        
        int preMaxHeight = 0;
        
        for(int i = 0; i < prev.size(); i++){
            
            if(prev[i][1] < temp[0]) continue;
            if(prev[i][0] > temp[1]) continue;
            
            preMaxHeight = max(preMaxHeight, prev[i][2]);
        }
        
        temp[2] += preMaxHeight;
        prev.push_back(temp);
        return temp[2];
    }
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        
        vector<int> res;
        vector<vector<int>> prev;
        int h = 0;
        for(int i = 0; i < positions.size(); i++){
            int end = positions[i][0] + positions[i][1] - 1;
            vector<int> temp = {positions[i][0], end, positions[i][1]};
            h = max(h, getMaxHeight(prev, temp));
            res.push_back(h);
        }
        return res;
    }
};
