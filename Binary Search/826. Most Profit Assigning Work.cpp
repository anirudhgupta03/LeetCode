class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        int n = difficulty.size();
        
        vector<pair<int,int>> v(n);
        
        for(int i = 0; i < n; i++){
            v[i] = {difficulty[i], profit[i]};
        }
        
        sort(v.begin(),v.end());
        
        vector<int> temp(n);
        temp[0] = v[0].second;
        
        for(int i = 1; i < n; i++){
            temp[i] = max(v[i].second, temp[i-1]);
        }
        
        
        int maxprofit = 0;
        for(int i = 0; i < worker.size(); i++){
            
            int lo = 0, hi = n - 1;
            int ans = - 1;
            
            while(lo <= hi){
                int mid = (lo + hi)/2;
                
                if(v[mid].first <= worker[i]){
                    ans = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            if(ans != -1){
                maxprofit += temp[ans];
            }
        }
        return maxprofit;
    }
};
