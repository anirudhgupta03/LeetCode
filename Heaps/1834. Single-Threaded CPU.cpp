//Ref: https://leetcode.com/problems/single-threaded-cpu/discuss/1164008/C%2B%2B-min-heap
class Solution {
public:
    #define pii pair<int,int>
    struct cmp{
        bool operator()(pair<int,int> p1, pair<int,int> p2){
            
            if(p1.second == p2.second){
                return p1.first > p2.first;
            }
            return p1.second > p2.second;
        }
    };
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        vector<int> res;
        
        for(int i = 0; i < tasks.size(); i++){
            tasks[i].push_back(i);
        }
        
        sort(tasks.begin(),tasks.end());          //The tasks which comes first 
        
        priority_queue<pii,vector<pii>,cmp> pq;
        
        int i = 0; 
        
        while(i < tasks.size()){
            
            int start = tasks[i][0];
            
            while(i < tasks.size() && tasks[i][0] == start){  
                pq.push(tasks[i][2],tasks[i][1]);
                i++;
            }
            
            long long total_time = start;
            
            while(!pq.empty()){

                int ind = pq.top().first;
                int process_time = pq.top().second;
                total_time += process_time;
                
                res.push_back(ind);
                
                pq.pop();
                
                int j = i;
                
                for(j = i; j < tasks.size(); j++){
                    if(tasks[j][0] <= total_time){
                        pq.push(tasks[j][2],tasks[j][1]);
                    }
                    else{
                        break;
                    }
                }
                
                i = j;
            }
        }
        return res;
    }
};
