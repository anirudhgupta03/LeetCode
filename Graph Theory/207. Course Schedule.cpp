class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> res;
        
        vector<int> in(numCourses,0);
        
        vector<int> al[numCourses];
        
        for(int i = 0; i < prerequisites.size(); i++){
            
            int a = prerequisites[i][0], b = prerequisites[i][1]; 
            al[a].push_back(b);
            in[b]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            
            for(int i = 0; i < al[curr].size(); i++){
                in[al[curr][i]]--;
                if(in[al[curr][i]] == 0){
                    q.push(al[curr][i]);
                }
            }
        }
        
        if(res.size() == numCourses){
            return true;
        }
        return false;
    }
};
