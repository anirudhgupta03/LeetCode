//Method - 1
//Ref: https://leetcode.com/problems/validate-binary-tree-nodes/discuss/899238/Simple-C%2B%2B-and-Python-solution-with-explanation
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        vector<int> parents(n,0);
        
        for(int i = 0; i < n; i++){
            
            int u = leftChild[i], v = rightChild[i];
            
            if(u != -1){
                parents[u]++;
            }
            if(v != -1){
                parents[v]++;
            }
        }
        
        queue<int> nodes;
        
        for(int i = 0; i < n; i++){
            
            if(parents[i] == 0){
                nodes.push(i);
            }
            else if(parents[i] > 1){
                return false;
            }
        }
        
        if(nodes.size() != 1){
            return false;
        }
        
        unordered_set<int> seen;
        
        while(!nodes.empty()){
            
            int node = nodes.front();
            nodes.pop();
            
            if(node == -1){
                continue;
            }
            
            if(seen.find(node) != seen.end()){
                return false;
            }
            seen.insert(node);
            nodes.push(leftChild[node]);
            nodes.push(rightChild[node]);
        }
        
        return (seen.size()==n);
    }
};

//Method - 2
class Solution {
public:
    bool dfs(int node, vector<int> al[], vector<int> &vis){
        
        vis[node] = 1;
        
        for(int i = 0; i < al[node].size(); i++){
            int child = al[node][i];
            if(vis[child] == 0){
                bool flag = dfs(child, al, vis);
                if(flag) return true;
            }
            else if(vis[child] == 1){
                return true;
            }
        }
        return false;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        vector<int> al[n], indegree(n, 0);
        
        for(int i = 0; i < n; i++){
            if(leftChild[i] != -1){
                al[i].push_back(leftChild[i]);
                indegree[leftChild[i]]++;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(rightChild[i] != -1){
                al[i].push_back(rightChild[i]);
                indegree[rightChild[i]]++;
            }
        }
        
        vector<int> vis(n, 0);
        int count = 0;
        
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                count++;
                bool flag = dfs(i, al, vis);
                if(flag) return false;
            }
        }
        if(count == 0 || count >= 2) return false;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0) return false;
        }
        return true;
    }
};
