struct TrieNode{
    TrieNode* child[2];
    TrieNode(){
        child[0] = child[1] = nullptr;
    }
};
class Solution {
public:
    void insert(TrieNode* curr, int x){
        for(int i = 30; i >= 0; i--){
            int bit = 0;
            if(x & (1 << i)){
                bit = 1;
            }
            if(curr -> child[bit] == nullptr){
                curr -> child[bit] = new TrieNode();
            }
            curr = curr -> child[bit];
        }
    }
    int findMaxXOR(TrieNode* curr, int x){
        int ans = 0;
        for(int i = 30; i >= 0; i--){
            int bit = 0;
            if(x & (1 << i)){
                bit = 1;
            }
            if(curr -> child[1 - bit]){
                ans += (1 << i);
                curr = curr -> child[1 - bit];
            }
            else{
                curr = curr -> child[bit];
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        
        int n = nums.size();
        TrieNode* head = new TrieNode();

        for(int &x: nums){
            insert(head, x);
        }
        int ans = 0;
        for(int &x: nums){
            ans = max(ans, findMaxXOR(head, x));
        }
        return ans;
    }
};
