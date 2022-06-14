//Method - 1
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

//Method - 2
//Floyd Warshall Algorithm
//Ref: https://www.youtube.com/watch?v=sYrCIA80c5c
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<int>> dist(numCourses, vector<int>(numCourses, INT_MAX));
        
        for(auto &x: prerequisites){
            dist[x[0]][x[1]] = 1;
        }
        
        for(int k = 0; k < numCourses; k++){
            for(int i = 0; i < numCourses; i++){
                for(int j = 0; j < numCourses; j++){
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        vector<bool> res;
        for(auto &x: queries){
            if(dist[x[0]][x[1]] != INT_MAX){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }
        return res;
    }
};
