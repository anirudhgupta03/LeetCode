//Ref: https://www.youtube.com/watch?v=XZlH06iGvtg
class ThroneInheritance {
public:
    unordered_map<string,vector<string>> umap;
    unordered_set<string> dead;
    string root;
    ThroneInheritance(string kingName) {
        umap.clear();
        dead.clear();
        root = kingName;
    }
    
    void birth(string parentName, string childName) {
        umap[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    void dfs(string root, vector<string> &res){
        if(dead.find(root) == dead.end()){
            res.push_back(root);
        }
        for(string child: umap[root]){
            dfs(child, res);
        }
    }
    vector<string> getInheritanceOrder() {
        vector<string> res;
        dfs(root, res);
        return res;
    }
};
/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
