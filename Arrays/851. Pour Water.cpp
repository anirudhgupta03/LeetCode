//https://www.lintcode.com/problem/851/
class Solution {
public:
    /**
     * @param heights: the height of the terrain
     * @param V: the units of water
     * @param K: the index
     * @return: how much water is at each index
     */
    vector<int> pourWater(vector<int> &heights, int V, int K) {
        
        for(int i = 1; i <= V; i++){

            int minleft = INT_MAX, left = -1, right = -1, minright = INT_MAX;

            for(int j = K - 1; j >= 0; j--){
                if(heights[j] <= heights[K]){
                    if(left == -1){
                        if(heights[j] < heights[K]){
                            left = j;
                            minleft = heights[j];
                        }
                    }
                    else{
                        if(heights[j] <= minleft){
                            if(heights[j] < minleft)
                            left = j;
                            minleft = heights[j];
                        }
                        else{
                            break;
                        }
                    }
                }
                else if(heights[j] > heights[K]){
                    break;
                }
            }

            if(left != -1){
                heights[left] += 1;
                for(int j = 0; j < heights.size(); j++){
                    cout << heights[j] << " ";
                }
                cout << endl;
                continue;
            }

            for(int j = K + 1; j < heights.size(); j++){
                if(heights[j] <= heights[K]){
                    if(right == -1){
                        if(heights[j] < heights[K]){
                            right = j;
                            minright = heights[j];
                        }
                    }
                    else{
                        if(heights[j] <= minright){
                            if(heights[j] < minright)
                            right = j;
                            minright = heights[j];
                        }
                        else{
                            break;
                        }
                    }
                }
                else if(heights[j] > heights[K]){
                    break;
                }
            }

            if(right != -1){
                heights[right] += 1;
                for(int j = 0; j < heights.size(); j++){
                    cout << heights[j] << " ";
                }
                cout << endl;
                continue;
            }

            heights[K] += 1;
            for(int j = 0; j < heights.size(); j++){
                cout << heights[j] << " ";
            }
            cout << endl;
        }
        return heights;
    }
};
