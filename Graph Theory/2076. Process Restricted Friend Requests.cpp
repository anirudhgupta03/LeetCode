//Ref: https://www.youtube.com/watch?v=ePg-pEUzWAU
//Method - 1
class Solution {
public:
    int findp1(int node, vector<int> &par){
        if(par[node] == node){
            return node;
        }
        return par[node] = findp1(par[node], par);
    }
    void unionp(int node1, int node2, vector<int> &par){
        par[node2] = node1;
    }
    int findp2(int node, vector<int> &par){
        if(par[node] == node){
            return node;
        }
        return findp2(par[node], par);
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        
        vector<int> par(n);
        
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
        
        vector<bool> res;
        
        for(int i = 0; i < requests.size(); i++){
            
            int u = requests[i][0], v = requests[i][1];
            
            int paru = findp1(u, par);
            int parv = findp1(v, par);
            
            if(paru == parv){
                res.push_back(true);
            }
            else{
                int temp = par[parv];
                par[parv] = paru;
                
                bool flag = true;
                
                for(int j = 0; j < restrictions.size(); j++){
                    int a = restrictions[j][0], b = restrictions[j][1];
                    int para = findp2(a, par);
                    int parb = findp2(b, par);
                    
                    if(para == parb){
                        flag = false;
                        par[parv] = temp;
                        break;
                    }
                }
                res.push_back(flag);
            }
        }
        return res;
    }
};

//Method - 2 (Union by Rank and Path Compression)
class Solution {
public:
    int findp1(int node, vector<int> &par){
        if(par[node] == node){
            return node;
        }
        return par[node] = findp1(par[node], par);
    }
    void unionp(int node1, int node2, vector<int> &par){
        par[node2] = node1;
    }
    int findp2(int node, vector<int> &par){
        if(par[node] == node){
            return node;
        }
        return findp2(par[node], par);
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        
        vector<int> par(n), rank(n, 1);
        
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
        
        vector<bool> res;
        
        for(int i = 0; i < requests.size(); i++){
            
            int u = requests[i][0], v = requests[i][1];
            
            int paru = findp1(u, par);
            int parv = findp1(v, par);
            
            if(paru == parv){
                res.push_back(true);
            }
            else{
                int temp1 = par[parv], temp2 = par[paru];
                bool flag1 = false, flag2 = false, flag3 = false;
                if(rank[paru] > rank[parv]){
                    par[parv] = paru;
                    flag1 = true;
                }
                else if(rank[paru] < rank[parv]){
                    par[paru] = parv;
                    flag2 = true;
                }
                else{
                    par[parv] = paru;
                    rank[paru]++;
                    flag3 = true;
                }
                
                bool flag = true;
                
                for(int j = 0; j < restrictions.size(); j++){
                    int a = restrictions[j][0], b = restrictions[j][1];
                    
                    int para = findp2(a, par);
                    int parb = findp2(b, par);
                    
                    if(para == parb){
                        flag = false;
                        break;
                    }
                }
                if(!flag){
                    if(flag1){
                        par[parv] = temp1;
                    }
                    else if(flag2){
                        par[paru] = temp2;
                    }
                    else{
                        par[parv] = temp1;
                        rank[paru]--;
                    }
                }
                res.push_back(flag);
            }
        }
        return res;
    }
};
