//Ref: https://www.youtube.com/watch?v=u0n-6zBnohY
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<int> pq;
        
        int minVal = INT_MAX;
        
        for(int i: nums){
            if(i % 2 == 1){
                i *= 2;
            }
            minVal = min(minVal, i);
            pq.push(i);
        }
        
        int diff = INT_MAX;
        while(!pq.empty() && pq.top() % 2 == 0){
            int maxVal = pq.top();
            pq.pop();
            diff = min(diff, maxVal - minVal);
            minVal = min(maxVal/2,minVal);
            pq.push(maxVal/2);
        }
        return min(diff, pq.top() - minVal);
    }
};
