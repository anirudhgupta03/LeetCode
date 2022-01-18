//https://www.codingninjas.com/codestudio/problems/the-earliest-moment-when-everyone-become-friends_1376604?leftPanelTab=0
//Ref: https://www.youtube.com/watch?v=xW2hjWl19is
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
