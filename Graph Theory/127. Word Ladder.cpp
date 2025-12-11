class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord){
            return 0;
        }
        unordered_set<string> dictionary;
        for(auto &word: wordList){
            dictionary.insert(word);
        }
        if(dictionary.find(endWord) == dictionary.end()){
            return 0;
        }
        queue<string> q;
        q.push(beginWord);

        unordered_set<string> vis;
        vis.insert(beginWord);

        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){
                string str = q.front();
                q.pop();
                if(str == endWord){
                    return ans;
                }
                for(int i = 0; i < str.size(); i++){
                    char chh = str[i];
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        if(chh == ch) continue;
                        str[i] = ch;
                        if(dictionary.find(str) != dictionary.end() && vis.find(str) == vis.end()){
                            q.push(str);
                            vis.insert(str);
                        }
                    }
                    str[i] = chh;
                }
            }
        }
        return 0;
    }
};
