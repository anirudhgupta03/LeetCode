//https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/
//Using DFS
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> al[]){

    vis[node] = 1;

    for(int i = 0; i < al[node].size(); i++){
        int child = al[node][i];
        if(!vis[child]){
            dfs(child, vis, al);
        }
    }
}
int main(){

    int n, e;
    cin >> n >> e;

    vector<int> al[n + 1];

    int a, b;

    for(int i = 0; i < e; i++){
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }

    vector<int> vis(n + 1, 0);
    int cc_count = 0;

    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            cc_count++;
            dfs(i, vis, al);
        }
    }
    cout << cc_count << endl;
}

//Using Union-Find
#include<bits/stdc++.h>
using namespace std;

int findp(int node, vector<int> &par){
    if(par[node] == node){
        return node;
    }
    return par[node] = findp(par[node], par);
}
void unionp(int node1, int node2, vector<int> &par){
    par[node2] = node1;
}
int main(){

    int n, e;
    cin >> n >> e;

    vector<int> par(n + 1);
    for(int i = 1; i <= n; i++){
        par[i] = i;
    }

    int a, b;
    
    for(int i = 0; i < e; i++){
        cin >> a >> b;
        int para = findp(a, par);
        int parb = findp(b, par);

        if(para != parb){
            unionp(para, parb, par);
        }
    }

    unordered_map<int,int> parents;
    for(int i = 1; i <= n; i++){
        parents[par[i]]++;
    }
    cout << parents.size() << endl;
}
