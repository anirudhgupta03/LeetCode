bool cmp(vector<int> v1, vector<int> v2){
        
        return v1[1] < v2[1];
}
class Solution {
public:
    
    int findLatestJob(int startTime, int ind, vector<int> &endTime){
        
        int lo = 0, hi = ind, ans = -1;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(endTime[mid] <= startTime){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        
        vector<vector<int>> v(n);
        
        for(int i = 0; i < endTime.size(); i++){
            v[i].push_back(startTime[i]);
            v[i].push_back(endTime[i]);
            v[i].push_back(profit[i]);
        }
        
        sort(v.begin(),v.end(),cmp);
        
        for(int i = 0; i < n; i++){
            startTime[i] = v[i][0];
            endTime[i] = v[i][1];
            profit[i] = v[i][2];
            //cout << startTime[i] <<  " " << endTime[i] << " " << profit[i] << endl;
        }
        
        for(int i = 1; i < n; i++){
            
            int inc = findLatestJob(startTime[i],i - 1,endTime);
            
            if(inc == -1)
            profit[i] = max(profit[i-1], profit[i]);
            else
            profit[i] = max(profit[i-1], profit[i] + profit[inc]);
            
            //cout << profit[i] << " ";
        }
        
        int maxprofit = INT_MIN;
        for(auto x : profit){
            maxprofit = max(x,maxprofit);
        }
        return maxprofit;
    }
};
