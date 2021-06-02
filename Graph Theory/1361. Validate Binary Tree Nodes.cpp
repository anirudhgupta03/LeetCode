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
