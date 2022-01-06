//Ref: https://www.youtube.com/watch?v=DOHvkZ7QpAM
class SnapshotArray {
public:
    int sid;
    vector<unordered_map<int,int>> v;
    SnapshotArray(int length) {
        sid = 0;
        v.clear();
        v.resize(length);
    }
    
    void set(int index, int val) {
        v[index][sid] = val;
    }
    
    int snap() {
        sid++;
        return sid - 1;
    }
    
    int get(int index, int snap_id) {
        while(snap_id >= 0 && v[index].find(snap_id) == v[index].end()){
            snap_id--;
        }
        if(snap_id == -1){
            return 0;
        }
        return v[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
