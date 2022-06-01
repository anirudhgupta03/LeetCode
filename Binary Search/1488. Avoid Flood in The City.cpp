//Ref: https://www.youtube.com/watch?v=OnVtJ_7T-6s
//Method - 1
class Solution {
public:
    bool dryDayExists(vector<int> &temp, int start, int end, int &ind, vector<int> &ans){
        
        int lo = 0, hi = temp.size() - 1;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(temp[mid] >= end){
                hi = mid - 1;
            }
            else if(temp[mid] <= start){
                lo = mid + 1;
            }
            else{
                if(ans[temp[mid]] == -100){
                    ind = mid;
                    hi = mid - 1;   
                }
                else{
                    lo = mid + 1;
                }
            }
        }
        if(ind == -1){
            return false;
        }
        return true;
    }
    vector<int> avoidFlood(vector<int>& rains) {
        
        vector<int> temp;
        
        unordered_map<int,int> umap;
        
        vector<int> ans(rains.size());
        
        for(int i = 0; i < rains.size(); i++){
            
            if(rains[i] != 0){
               if(umap.find(rains[i]) != umap.end()){
                    int ind = -1;
                    if(dryDayExists(temp, umap[rains[i]], i, ind, ans)){
                        ans[temp[ind]] = rains[i];
                        umap[rains[i]] = i;
                        //temp.erase(temp.begin() + ind);               //Gives TLE
                        ans[i] = -1;
                    }   
                    else{
                        vector<int> temp;
                        return temp;
                    }
               } 
               else{
                   umap[rains[i]] = i;
                   ans[i] = -1;
               }
            }
            else{
                temp.push_back(i);
                ans[i] = -100;
            }
        }
        for(int i = 0; i < rains.size(); i++){
            if(ans[i] == -100){
                ans[i] = 1;
            }
        }
        return ans;
    }
};

//Method - 2
class Solution {
public:
    int findDryDay(int start, int end, vector<int> &daysToDryLake, vector<int> &vis){
        
        int lo = 0, hi = daysToDryLake.size() - 1, ind = -1;
        
        while(lo <= hi){
            
            int mid = lo + (hi - lo)/2;
            
            if(daysToDryLake[mid] < start){
                lo = mid + 1;
            }
            else if(daysToDryLake[mid] > end){
                hi = mid - 1;
            }
            else{
                if(vis[mid] == 1){
                    lo = mid + 1;
                }
                else{
                    ind = mid;
                    hi = mid - 1;
                }
            }
        }
        return ind;
    }
    vector<int> avoidFlood(vector<int>& rains) {
        
        int n = rains.size();
        
        unordered_map<int,int> days;
        
        vector<int> daysToDryLake, vis;
        
        vector<int> res(n);
        
        for(int i = 0; i < n; i++){
            
            if(rains[i] == 0){
                daysToDryLake.push_back(i);
                vis.push_back(0);
            }
            else{
                if(days.find(rains[i]) == days.end()){
                    days[rains[i]] = i;
                    res[i] = -1;
                }
                else{
                    int ind = findDryDay(days[rains[i]] + 1, i - 1, daysToDryLake, vis);
                    if(ind == -1){
                        vector<int> temp;
                        return temp;
                    }
                    else{
                        vis[ind] = 1;
                        res[daysToDryLake[ind]] = rains[i]; 
                        res[i] = -1;
                        days[rains[i]] = i;   
                    }
                }
            }
        }
        int ind = 0;
        for(int i = 0; i < n; i++){
            if(rains[i] == 0){
                if(vis[ind] == 0) res[i] = 1;
                ind++;
            }
        }
        return res;
    }
};
