class LockingTree {
public:
    unordered_map<int,int> locked;
    vector<vector<int>> al;
    vector<int> par;
    int n;
    void dfs(int num, bool &flag){ 
        if(locked.find(num) != locked.end()){
           locked.erase(num);
           flag = true;
        }
        for(int i = 0; i < al[num].size(); i++){
            int child = al[num][i];
            dfs(child, flag);
        }
    }
    LockingTree(vector<int>& parent) {
        n = parent.size();
        al.resize(n);
        par = parent;
        for(int i = 0; i < n; i++){
            int a = parent[i], b = i;
            if(a == -1) continue;
            al[a].push_back(b);
        }
    }
    
    bool lock(int num, int user) {
        if(locked.find(num) != locked.end()){
            return false;
        }
        locked[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(locked.find(num) != locked.end()){
            if(locked[num] == user){
                locked.erase(num);
                return true;
            }
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        if(locked.find(num) != locked.end()){
            return false;
        }
        int temp = num;
        while(par[num] != -1){
            num = par[num];
            if(locked.find(num) != locked.end()){
                return false;
            }
        }
        num = temp;
        bool flag = false;
        dfs(num, flag);
        if(!flag){
            return false;
        }
        locked[num] = user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
