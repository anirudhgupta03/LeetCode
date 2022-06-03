//Binary Search + Priority Queue
class Solution {
public:
    #define pii pair<int,int>
    struct cmp{
        bool operator()(pii &p1, pii &p2){
            if(p1.second == p2.second){
                return p1.first < p2.first;
            }
            return p1.second < p2.second;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int m = mat.size(), n = mat[0].size();
        
        priority_queue<pii, vector<pii>, cmp> pq;
        
        for(int i = 0; i < m; i++){
            
            int lo = 0, hi = n - 1, ans = -1;
            
            while(lo <= hi){
                
                int mid = (lo + hi)/2;
                
                if(mat[i][mid] == 1){
                    ans = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            
            pq.push({i, ans + 1});
            if(pq.size() > k) pq.pop();
        }
        
        vector<int> res;
        
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
