struct cmp {
    bool operator()(pair<int,int> p1,pair<int,int> p2) {
        
        if(p1.first == p2.first)  return p1.second < p2.second;
        return p1.first > p2.first;
    }
};
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int,int> umap;
        
        for(auto x : nums){
            umap[x]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        
        for(int i = 0; i < nums.size(); i++){
            pq.push({umap[nums[i]],nums[i]});
        }
        
        vector<int> res;
        
        while(pq.size()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};
