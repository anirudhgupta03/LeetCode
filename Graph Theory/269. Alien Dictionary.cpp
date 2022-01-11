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
