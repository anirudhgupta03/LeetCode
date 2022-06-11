//https://www.codingninjas.com/codestudio/problems/the-earliest-moment-when-everyone-become-friends_1376604?leftPanelTab=0
//Ref: https://www.youtube.com/watch?v=xW2hjWl19is
//Method - 1
#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &v1, vector<int> &v2){
    return v1[0] < v2[0];
}
int findp(int node, vector<int> &par){
    if(par[node] == node){
        return node;
    }
    return par[node] = findp(par[node], par);
}
void unionp(int node1, int node2, vector<int> &par){
    par[node2] = node1;
}
int minTime(vector<vector<int>> &logs, int n)
{
	sort(logs.begin(), logs.end(), cmp);
    
    vector<int> par(n);
    
    for(int i = 0; i < n; i++){
        par[i] = i;
    }
    
    for(int i = 0; i < logs.size(); i++){
        int time = logs[i][0], a = logs[i][1], b = logs[i][2];
        
        int para = findp(a, par);
        int parb = findp(b, par);
        
        if(para != parb){
            n--;
            unionp(para, parb, par);
        }
        if(n == 1){
            return time;
        }
    }
    return -1;
}

//Method - 2
#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &v1, vector<int> &v2){
    return v1[0] < v2[0];
}
void unionP(int node1, int node2, vector<int> &par){
    par[node2] = node1;
}
int findP(int node, vector<int> &par){
    if(par[node] == -1){
        return node;
    }
    return par[node] = findP(par[node], par);
}
int minTime(vector<vector<int>> &logs, int n)
{
	sort(logs.begin(), logs.end(), cmp);
    
    int ans = 0;
    
    vector<int> par(n, -1);
    
    for(int i = 0; i < logs.size(); i++){
        int t = logs[i][0], u = logs[i][1], v = logs[i][2];
        
        int paru = findP(u, par);
        int parv = findP(v, par);

        if(paru != parv){
            ans = t;
            unionP(paru, parv, par);
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        if(par[i] == -1){
            count++;
        }
    }
    if(count > 1) return -1;
    return ans;
}
