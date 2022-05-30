//https://www.codingninjas.com/codestudio/problems/common-element-in-rows_975481?leftPanelTab=0
//https://leetcode.ca/all/1198.html
//Method - 1
//TC - O(N*M*logN)
//SC - O(1)
#include<bits/stdc++.h>
bool isPresentInAllRows(int ele, vector<vector<int>> &mat, int m, int n){
    for(int i = 1; i < m; i++){
        int lo = 0, hi = n - 1;
        bool flag = false;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(mat[i][mid] > ele){
                hi = mid - 1;
            }
            else if(mat[i][mid] == ele){
                flag = true;
                break;
            }
            else{
                lo = mid + 1;
            }
        }
        if(!flag) return false;
    }
    return true;
}
int smallestCommonElement(int m, int n, vector<vector<int>>& mat) {    
    
    for(int i = 0; i < n; i++){
        if(isPresentInAllRows(mat[0][i], mat, m, n)){
            return mat[0][i];
        }
    }
    return -1;
}

//Method - 2
//TC - O(N*M)
//SC - O(M)
#include<bits/stdc++.h>
int smallestCommonElement(int m, int n, vector<vector<int>>& mat) {
    
    unordered_map<int,int> umap;
    
    for(int j = 0; j < n; j++){
        if(umap[mat[0][j]] == 0) umap[mat[0][j]]++;
    }
    
    for(int i = 1; i < m; i++){
        for(int j = 0; j < n; j++){
            if(umap[mat[i][j]] == i) umap[mat[i][j]]++;
        }
    }
    
    int minEle = INT_MAX;
    
    for(auto &x: umap){
        if(x.second == m) minEle = min(minEle, x.first);
    }
    return minEle == INT_MAX ? -1 : minEle;
}
