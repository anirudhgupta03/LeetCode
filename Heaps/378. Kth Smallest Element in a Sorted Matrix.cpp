class Solution {
public:
    #define pipii pair<int,pair<int,int>>
    struct cmp{
        bool operator()(pipii p1, pipii p2){
            return p1.first > p2.first;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<pipii,vector<pipii>,cmp> pq;
        
        for(int i = 0; i < matrix.size(); i++){
            pq.push({matrix[i][0],{i,0}});
        }
        
        int ele;
      
        while(k){
            int i = pq.top().second.first, j = pq.top().second.second;
            ele = pq.top().first;
            pq.pop();
            k--;
            
            if(j < matrix.size() - 1){
                pq.push({matrix[i][j+1],{i,j+1}});
                j++;
            }
        }
        return ele;
    }
};
