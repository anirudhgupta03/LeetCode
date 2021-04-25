class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> umap;
        
        for(int i = 0; i < nums.size(); i++){
            umap[nums[i]]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        unordered_map<int,int> :: iterator it;
        
        for(it = umap.begin(); it != umap.end(); it++){
            
            pq.push({it->second,it->first});
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<int> res;
        
        while(pq.size()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};
