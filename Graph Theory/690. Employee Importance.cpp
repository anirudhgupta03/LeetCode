//Method - 1
//Using BFS
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        queue<int> q;
        q.push(id);
        
        unordered_set<int> vis;
        
        int totalImportance = 0;
        while(!q.empty()){
          
            int curr = q.front();
            q.pop();
            if(vis.find(curr) != vis.end()) continue;
            vis.insert(curr);  
            for(int i = 0; i < employees.size(); i++){
                if(employees[i] -> id == curr){
                    totalImportance += employees[i] -> importance;
                    vector<int> v = employees[i] -> subordinates;
                    for(int j = 0; j < v.size(); j++){
                        if(vis.find(v[j]) == vis.end()){
                            q.push(v[j]);
                        }
                    }
                    break;
                }
            }
        }
        return totalImportance;
    }
};

//Method - 2
//Using DFS
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        int totalImportance = 0;
        
        for(auto &x: employees){
            if(x -> id == id){
                totalImportance += x -> importance;
                for(auto &y: x -> subordinates){
                    totalImportance += getImportance(employees, y);
                }
            }
        }
        return totalImportance;
    }
};
