class Solution {
public:
    #define psi pair<string,int>
    struct TrieNode{
        int freq;
        TrieNode* child[26];
        TrieNode(){
            freq = 0;
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
            }
        }
    };
    struct cmp{
        bool operator()(psi p1, psi p2){
            if(p1.second == p2.second){
                return p1.first < p2.first;
            }
            return p1.second > p2.second;
        }
    };
    void insert(TrieNode* root, string s){
        
        for(int i = 0; i < s.size(); i++){
            if(root -> child[s[i] - 'a'] == NULL){
                root -> child[s[i] - 'a'] = new TrieNode();
            }
            root = root -> child[s[i] - 'a'];
        }
        root -> freq++;
    }
    int search(TrieNode* root, string s){
        
        for(int i = 0; i < s.size(); i++){
            root = root -> child[s[i] - 'a'];
        }
        return root -> freq;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        TrieNode* root = new TrieNode();
        unordered_set<string> us;
        
        for(int i = 0; i < words.size(); i++){
            us.insert(words[i]);
            insert(root, words[i]);
        }
        
        vector<string> v(k);
        int ind = k - 1;
        
        priority_queue<psi,vector<psi>,cmp> pq;
        
        for(auto x: us){
            int frequency = search(root, x);
            
            cout << x << " " << frequency << endl;
            
            pq.push({x, frequency});
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            v[ind] = pq.top().first;
            pq.pop();
            ind--;
        }
        return v;
    }
};
