class Solution {
public:
    int maximumGap(vector<int>& A) {
        
        int n = A.size();
    
        if(n <= 1) return 0;

        int minEle = *min_element(A.begin(), A.end());
        int maxEle = *max_element(A.begin(), A.end());

        int diff = maxEle - minEle;

        int gap = (int)(ceil)(1.0*diff/(n - 1));

        if(gap == 0) gap = 1;

        vector<pair<int,int>> buckets(n, {INT_MAX, INT_MIN});

        for(int i = 0; i < n; i++){
            int bucketInd = (A[i] - minEle)/gap;
            buckets[bucketInd].first = min(buckets[bucketInd].first, A[i]);
            buckets[bucketInd].second = max(buckets[bucketInd].second, A[i]);
        }
        int ansgap = 0;

        for(int i = 0; i < n; i++){
            if(buckets[i].first == INT_MAX) continue;
            ansgap = max(ansgap, buckets[i].first - minEle);
            minEle = buckets[i].second;
        }
        return ansgap;
    }
};
