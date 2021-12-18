//https://www.lintcode.com/problem/861/
//Ref: https://www.youtube.com/watch?v=ioKRhlQyPnU
class Solution {
public:
    /**
     * @param flowers: the place where the flower will open in that day
     * @param k:  an integer
     * @return: in which day meet the requirements
     */
    int kEmptySlots(vector<int> &flowers, int k) {
        
        int n = flowers.size();
        int maxday = INT_MIN;
      
        for(int i = 0; i < n; i++){
            maxday = max(maxday, flowers[i]);
        }
        vector<int> pos(maxday + 1);

        for(int i = 0; i < n; i++){
            pos[flowers[i]] = i + 1;
        }

        int start = 1, end = k + 2;

        int ans = INT_MAX;

        for(int i = 2; i <= maxday; i++){

            if(pos[i] > pos[start] && pos[i] > pos[end]) continue;
            if(i == end){
                ans = min(ans, max(pos[start], pos[end]));
            }
            start = i;
            end = i + k + 1;
            if(end > maxday){
                break;
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
