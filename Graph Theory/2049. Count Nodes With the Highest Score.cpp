class Solution {
public:
    #define ll long long
    int solve(int node, vector<ll> &temp1, vector<ll> &temp2, vector<ll> &vis, vector<ll> al[]){
        
        vis[node] = 1;
        ll prod = 1, sum = 1;
        
        for(int i = 0; i < al[node].size(); i++){
            int child = al[node][i];
            if(vis[child] == 0){
                ll t = solve(child, temp1, temp2, vis, al);
                prod *= t;
                sum += t;
            }
        }
        temp1[node] = prod;
        temp2[node] = sum;
        return sum;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        
        int n = parents.size();
        
        vector<ll> al[n];
        
        for(int i = 0; i < n; i++){
            if(parents[i] == -1){
                continue;
            }
            int a = i, b = parents[i];
            al[a].push_back(b);
            al[b].push_back(a);
        }
        
        vector<ll> temp1(n, 1), temp2(n, 1), vis(n, 0);
        solve(0, temp1, temp2, vis, al);
        
        vector<ll> scores(n);
        ll maxfreq = 0;
        
        for(int i = 0; i < n; i++){
            if(parents[i] == -1){
                scores[i] = temp1[i];
            }
            else{
                scores[i] = temp1[i]*(n - temp2[i]);   
            }
            maxfreq = max(maxfreq, scores[i]);
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(scores[i] == maxfreq) count++;
        }
        return count;
    }
};
