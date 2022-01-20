//Ref: https://www.youtube.com/watch?v=HTSz54xEw70&t=70s
//Using Min Heap
class Solution {
public:
    #define pii pair<int,int>
    struct cmp{
      bool operator()(pii p1, pii p2){
          return p1.second > p2.second;
      }  
    };
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        vector<pii> al[n];
        
        for(int i = 0; i < meetings.size(); i++){
            int x = meetings[i][0], y = meetings[i][1], t = meetings[i][2];
            al[x].push_back({y,t});
            al[y].push_back({x,t});
        }
        vector<int> vis(n, 0);
        
        priority_queue<pii, vector<pii>, cmp> pq;
        pq.push({0,0});
        pq.push({firstPerson,0});
        
        vector<int> res;
        
        while(!pq.empty()){
            int curr = pq.top().first, currt = pq.top().second;
            pq.pop();
            
            if(vis[curr]){
                continue;
            }
            vis[curr] = 1;
            res.push_back(curr);
            
            for(int i = 0; i < al[curr].size(); i++){
                int child = al[curr][i].first;
                if(vis[child] == 0 && al[curr][i].second >= currt){
                    pq.push({child, al[curr][i].second});
                }
            }
        }
        return res;
    }
};

//Using DSU
class Solution {
public:
    int findp(int node, vector<int> &par){
        if(par[node] == node){
            return node;
        }
        return par[node] = findp(par[node], par);
    }
    void unionp(int node1, int node2, vector<int> &par){
        int par1 = findp(node1, par);
        int par2 = findp(node2, par);
        
        if(par1 == 0){
            par[par2] = par1;
        }
        else if(par2 == 0){
            par[par1] = par2;
        }
        else{
            par[par2] = par1;
        }
    }
    bool static cmp(vector<int> &v1, vector<int> &v2){
        return v1[2] < v2[2];
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        sort(meetings.begin(), meetings.end(), cmp);
        
        vector<int> par(n);
        
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
        
        par[firstPerson] = 0;
        
        int i = 0;
        
        while(i < meetings.size()){
            
            int currt = meetings[i][2];
            
            vector<int> persons;
            
            while(i < meetings.size()){
                if(meetings[i][2] == currt){
                    persons.push_back(meetings[i][0]);
                    persons.push_back(meetings[i][1]);
                    unionp(meetings[i][0], meetings[i][1], par);
                    i++;
                }
                else{
                    break;
                }
            }
            for(int j = 0; j < persons.size(); j++){
                int parj = findp(persons[j], par);
                if(parj != 0){
                    par[persons[j]] = persons[j];
                }
            }
        }
        vector<int> res;
        for(int i = 0; i < n; i++){
            int pari = findp(i, par);
            if(pari == 0){
                res.push_back(i);
            }
        }
        return res;
    }
};
