//https://leetcode.com/problems/course-schedule-iv/discuss/1535210/C%2B%2B-or-Kahn's-Algorithm-or-Short-and-simple-or-Explained
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<bool> res(queries.size(), false);
        
        vector<int> al[numCourses];
        
        vector<vector<bool>> table(numCourses, vector<bool>(numCourses, false));
        
        vector<int> in(numCourses, 0);
        
        for(int i = 0; i < prerequisites.size(); i++){
            al[prerequisites[i][0]].push_back(prerequisites[i][1]);
            in[prerequisites[i][1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(in[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            
            int curr = q.front();
            q.pop();
            
            for(int i = 0; i < al[curr].size(); i++){
                int child = al[curr][i];
                table[curr][child] = true;
                for(int j = 0; j < numCourses; j++){
                    if(table[j][curr]){
                        table[j][child] = true;
                    }
                }
                in[child]--;
                if(in[child] == 0) q.push(child);
            }
        }
        
        for(int i = 0; i < queries.size(); i++){
            res[i] = table[queries[i][0]][queries[i][1]];
        }
        return res;
    }
};
