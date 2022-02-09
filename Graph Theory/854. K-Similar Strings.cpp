//Ref: https://leetcode.com/problems/k-similar-strings/discuss/151500/Logical-Thinking-with-Clear-Java-Code
class Solution {
public:
    vector<string> getNeighbors(string curr, string B){
        
        vector<string> res;
        
        int i;
        
        for(i = 0; i < curr.size(); i++){
            if(curr[i] != B[i]){
                break;
            }
        }
        
        for(int j = i + 1; j < curr.size(); j++){
            if(curr[j] == B[i]){
                swap(curr[i], curr[j]);
                res.push_back(curr);
                swap(curr[i], curr[j]);
            }
        }
        return res;
    }
    int kSimilarity(string s1, string s2) {
        
        int n = s1.size();
        
        queue<string> q;
        q.push(s1);
        
        int steps = 0;
        
        unordered_set<string> vis;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curr = q.front();
                q.pop();
                
                if(curr == s2){
                    return steps;
                }
                
                if(vis.find(curr) != vis.end()) continue;
                vis.insert(curr);
                
                for(string neighbor: getNeighbors(curr, s2)){
                    if(vis.find(neighbor) == vis.end()){
                        q.push(neighbor);
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};
