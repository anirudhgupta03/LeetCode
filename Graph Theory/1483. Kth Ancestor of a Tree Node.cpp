//Ref: https://www.youtube.com/watch?v=PE-kQVZxvWA
//Binary Lifting
class TreeAncestor {
public:
    vector<vector<int>> table;
    TreeAncestor(int n, vector<int>& parent) {
        table.resize(17, vector<int>(n));
        for(int i = 0; i < n; i++){
            table[0][i] = parent[i];
        }
        
        for(int i = 1; i < 17; i++){
            for(int j = 0; j < n; j++){
                if(table[i-1][j] == -1){
                    table[i][j] = -1;
                }
                else{
                    table[i][j] = table[i-1][table[i-1][j]];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        
        for(int i = 0; i < 17; i++){
            int mask = (1 << i);
            if((k & mask) != 0){
                node = table[i][node]; 
            }
            if(node == -1){
                break;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
