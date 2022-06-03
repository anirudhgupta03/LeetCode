class SnapshotArray {
public:
    unordered_map<int,vector<pair<int,int>>> umap;
    int count = 0;
    SnapshotArray(int length) {
        umap.clear();
        for(int i = 0; i < length; i++){
            umap[i].push_back({0,0});
        }
    }
    
    void set(int index, int val) {
        if(umap[index].back().second == count){
            umap[index].back().first = val;
        }
        else{
            umap[index].push_back({val, count});
        }
    }
    
    int snap() {
        count++;
        return count - 1;
    }
    
    int get(int index, int snap_id) {
        
        int lo = 0, hi = umap[index].size() - 1, ans;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(umap[index][mid].second <= snap_id){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return umap[index][ans].first;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
