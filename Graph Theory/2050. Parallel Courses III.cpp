//Ref: https://leetcode.com/problems/parallel-courses-iii/discuss/1537479/C%2B%2BPython-Topology-Sort-O(M%2B-N)-Clean-and-Concise
//Method - 1
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        int minTime = 0;
        
        vector<int> al[n + 1], in(n + 1, 0);
        
        for(int i = 0; i < relations.size(); i++){
            int a = relations[i][0], b = relations[i][1];
            al[a].push_back(b);
            in[b]++;
        }
        
        queue<int> q;
        
        int temp = 0;
        
        vector<int> dist(n, 0);
        
        for(int i = 1; i <= n; i++){
            if(in[i] == 0){
                q.push(i);
                dist[i - 1] = time[i - 1];
            }
        }
    
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int curr = q.front();
                q.pop();
                
                for(int i = 0; i < al[curr].size(); i++){
                    int child = al[curr][i];
                    in[child]--;
                    dist[child - 1] = max(dist[child - 1], dist[curr - 1] + time[child - 1]);
                    if(in[child] == 0){
                        q.push(child);
                    }
                }
            }
        }
        return *max_element(dist.begin(),dist.end());
    }
};

//Method - 2
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<int> al[n + 1], indegree(n + 1, 0);
        
        for(auto &x: relations){
            al[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        
        queue<int> q;
        vector<int> ttime(n + 1, INT_MIN);
        
        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0){
                q.push(i);
                ttime[i] = time[i - 1];
            }
        }
        
        int minTime = INT_MIN;
        
        while(!q.empty()){
           
            int curr = q.front();
            q.pop();
            
            for(int i = 0; i < al[curr].size(); i++){
                int child = al[curr][i];
                if(ttime[curr] + time[child - 1] > ttime[child]){
                    ttime[child] = ttime[curr] + time[child - 1];
                    q.push(child);
                }
            }
        }
        return *max_element(ttime.begin(), ttime.end());
    }
};
