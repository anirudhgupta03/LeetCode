//Ref: https://www.youtube.com/watch?v=Q8LhG9Pi5KM
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
            if(curr == nullptr) return -1;
        }
        return ans;
    }
    bool static cmp(vector<int>& v1, vector<int>& v2){
        return v1[1] < v2[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();

        TrieNode* head = new TrieNode();

        sort(nums.begin(), nums.end());

        for(int i = 0; i< queries.size(); i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), cmp);

        int i = 0;
        vector<int> res(queries.size());

        for(int j = 0; j < queries.size(); j++){
            while(i < n && nums[i] <= queries[j][1]){
                insert(head, nums[i]);
                i++;
            }
            int maxXOR = findMaxXOR(head, queries[j][0]);
            res[queries[j][2]] = maxXOR;
        }
        
        return res;
    }
};
