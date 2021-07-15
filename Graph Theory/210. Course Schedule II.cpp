class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> res;
        
        vector<int> indegree(numCourses,0);
        
        vector<int> al[numCourses]; 
        
        for(int i = 0; i < prerequisites.size(); i++){
            
            int a = prerequisites[i][0], b = prerequisites[i][1];
            al[b].push_back(a);
            indegree[a]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            
            int curr = q.front();
            q.pop();
            
            res.push_back(curr);
            
            for(int i = 0; i < al[curr].size(); i++){
                indegree[al[curr][i]]--;
                
                if(indegree[al[curr][i]] == 0){
                    q.push(al[curr][i]);
                }
            }
        }
        
        if(res.size() == numCourses){
            return res;
        }
        res.clear();
        return res;
    }
};
