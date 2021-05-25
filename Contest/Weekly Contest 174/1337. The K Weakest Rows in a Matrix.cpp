class Solution {
public:
    #define pii pair<int,int>
    
    struct mycomp{
      bool operator()(pii p1, pii p2){
          if(p1.first == p2.first){
              return p1.second < p2.second;
          }
          return p1.first < p2.first;
      }  
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        priority_queue<pii,vector<pii>,mycomp> pq;
        
        for(int i = 0; i < mat.size(); i++){
            int count = 0;
            for(int j = 0; j < mat[i].size(); j++){
            
                if(mat[i][j] == 1){
                    count++;
                }
            }
            pq.push({count,i});
            if(pq.size() >k){
                pq.pop();
            }
        }
        
        vector<int> res;
        
        while(pq.size()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        
        return res;
    }
};
