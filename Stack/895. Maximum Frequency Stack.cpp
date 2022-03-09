class FreqStack {
public:
    #define pipii pair<int,pair<int,int>>
    unordered_map<int,int> umap;
    int dist = 0;
    
    struct cmp{
      bool operator()(pipii &p1, pipii &p2){
          if(p1.second.second == p2.second.second){
              return p1.first < p2.first;
          }
          return p1.second.second < p2.second.second;
      }  
    };
    priority_queue<pipii,vector<pipii>,cmp> pq;
    FreqStack() {
        while(!pq.empty()) pq.pop();
        umap.clear();
    }
    
    void push(int val) {
        umap[val]++;
        pq.push({dist,{val, umap[val]}});
        dist++;
    }
    
    int pop() {
        int val = pq.top().second.first;
        pq.pop();
        umap[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
