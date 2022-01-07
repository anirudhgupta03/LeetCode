//Ref: https://www.youtube.com/watch?v=OnVtJ_7T-6s
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
