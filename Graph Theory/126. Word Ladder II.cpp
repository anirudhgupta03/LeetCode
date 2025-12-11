class Solution {
public:
    string b;
    void dfs(string curr, vector<string>& seq, vector<vector<string>>& ans, unordered_map<string, int>& level, unordered_set<string>& st){
        if(curr == b){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = level[curr];
        for(int i = 0; i < curr.size(); i++){
            char original = curr[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                if(ch == original) continue;
                curr[i] = ch;
                if(st.find(curr) != st.end() && level[curr] + 1 == steps){
                    seq.push_back(curr);
                    dfs(curr, seq, ans, level, st);
                    seq.pop_back();
                }
            }
            curr[i] = original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        b = beginWord;
        vector<vector<string>> ans;
        unordered_map<string,int> level;
        unordered_set<string> st(wordList.begin(), wordList.end());
        unordered_set<string> vis;
        queue<string> q;
        
        level[beginWord] = 0;
        st.insert(beginWord);
        vis.insert(beginWord);
        q.push(beginWord);
        
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            int steps = level[curr];
            if(curr == endWord) break;
            for(int i = 0; i < curr.size(); i++){
                char originalch = curr[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    if(originalch != ch){
                        curr[i] = ch;
                        if(st.find(curr) != st.end() && vis.find(curr) == vis.end()){
                            q.push(curr);
                            vis.insert(curr);
                            level[curr] = steps + 1;
                        }
                    }
                }
                curr[i] = originalch;
            }
        }
        if(level.find(endWord) != level.end()){
            vector<string> seq = {endWord};
            dfs(endWord, seq, ans, level, st);
        }
        return ans;
    }
};
