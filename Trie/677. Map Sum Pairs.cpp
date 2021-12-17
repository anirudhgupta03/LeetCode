struct Node{
   
    Node* child[26];
    int val;
    
    Node(){
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
        val = 0;
    }
};

class MapSum {
public:
    Node* head;
    unordered_map<string,int> umap;
    
    MapSum() {
        head = new Node();
        umap.clear();
    }
    
    void insert(string key, int value) {
        if(umap.find(key) != umap.end()){
            int old = umap[key], newval = value;
            umap[key] = value;
            Node* temp = head;
            for(int i = 0; i < key.size(); i++){
                if(temp -> child[key[i] - 'a'] == NULL){
                    temp -> child[key[i] - 'a'] = new Node();
                }
                temp = temp -> child[key[i] - 'a'];
                temp -> val -= old;
                temp -> val += newval;
            }
            
        }
        else{
            umap[key] = value;
            Node* temp = head;
            for(int i = 0; i < key.size(); i++){
                if(temp -> child[key[i] - 'a'] == NULL){
                    temp -> child[key[i] - 'a'] = new Node();
                }
                temp = temp -> child[key[i] - 'a'];
                temp -> val += value;
            }
        }
        
    }
    
    int sum(string prefix) {
        Node* temp = head;
        
        for(int i = 0; i < prefix.size(); i++){
            if(temp -> child[prefix[i] - 'a'] != NULL){
                temp = temp -> child[prefix[i] - 'a'];
            }
            else{
                return 0;
            }
        }
        return temp -> val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
