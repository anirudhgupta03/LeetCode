//https://practice.geeksforgeeks.org/problems/alien-dictionary/1/#
//Topological Sort
class Solution{
    public:
    string findOrder(string dict[], int N, int k) {
        
        vector<int> al[k];
        vector<int> in(k,0);
        
        for(int i = 1; i < N; i++){
            string s1 = dict[i-1], s2 = dict[i];
            int j = 0;
            while(j < s1.size() && j < s2.size() && s1[j] == s2[j]){
                j++;
            }
            if(j < s1.size() && j < s2.size()){
                al[s1[j]-'a'].push_back(s2[j] - 'a');
                in[s2[j] - 'a']++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < k; i++){
            if(in[i] == 0) q.push(i);
        }
        string res;
        while(!q.empty()){
            int ind = q.front();
            q.pop();
            res.push_back(ind + 'a');
            
            for(int j = 0; j < al[ind].size(); j++){
                in[al[ind][j]]--;
                if(in[al[ind][j]] == 0){
                    q.push(al[ind][j]);
                }
            }
        }
        return res;
    }
};

//https://www.codingninjas.com/codestudio/problems/alien-dictionary_630423?leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;
vector<char> getAlienLanguage(string* dictionary, int n)
{
    vector<vector<int>> adj(26, vector<int>(26,0));
    vector<int> indegree(26, 0), freq(26, 0);
    
    for(int i = 1; i < n; i++){
        string prev = dictionary[i - 1], curr = dictionary[i];
        int ptr1 = 0, ptr2 = 0;
        
        while(ptr1 < prev.size() && ptr2 < curr.size()){
            if(prev[ptr1] != curr[ptr2]){
                freq[prev[ptr1] - 'a'] = 1;
                freq[curr[ptr2] - 'a'] = 1;
                if(adj[prev[ptr1] - 'a'][curr[ptr2] - 'a'] == 0){
                    adj[prev[ptr1] - 'a'][curr[ptr2] - 'a'] = 1;
                    indegree[curr[ptr2] - 'a']++;
                }
                break;
            }
            else{
                freq[prev[ptr1] - 'a'] = 1;
                ptr1++;
                ptr2++;
            }
        }
    }
    
    queue<int> q;
    for(int i = 0; i < 26; i++){
        if(indegree[i] == 0 && freq[i]){
            q.push(i);
        }
    }
    vector<char> res;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        res.push_back((char)(curr + 'a'));
        
        for(int i = 0; i < 26; i++){
            if(adj[curr][i]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
    }
    return res;
}
