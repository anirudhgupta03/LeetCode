class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        
        queue<string> q;
        q.push(s);
        
        unordered_set<string> vis;
        string ans = s;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curr = q.front();
                q.pop();
                
                if(vis.find(curr) != vis.end()) continue;
                vis.insert(curr);
                
                if(curr < ans){
                    ans = curr;
                }
                string temp = curr;
                
                for(int i = 1; i < temp.size(); i += 2){
                    int t = temp[i] - '0' + a;
                    temp[i] = (char)(t%10 + '0');
                }
                
                if(vis.find(temp) == vis.end()){
                    q.push(temp);
                }
                
                temp = curr;
                reverse(temp.begin(), temp.end());
                reverse(temp.begin(), temp.begin() + b);
                reverse(temp.begin() + b, temp.end());
                if(vis.find(temp) == vis.end()){
                    q.push(temp);
                }
            }
        }
        return ans;
    }
};
