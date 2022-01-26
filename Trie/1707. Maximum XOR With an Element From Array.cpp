//Ref: https://www.youtube.com/watch?v=Q8LhG9Pi5KM
class Solution {
public:
    #define ll long long
    struct TrieNode{
        TrieNode* child[2];
        TrieNode(){
            for(int i = 0; i < 2; i++){
                child[i] = NULL;
            }
        }
    };
    vector<int> binary(int num){
        
        vector<int> v(32);
        int ind = 31;
        while(ind >= 0){
            v[ind] = num % 2;
            num /= 2;
            ind--;
        }
        
        return v;
    }
    void insert(TrieNode* root, vector<int> bits){
        
        for(int i = 0; i < bits.size(); i++){
            if(root -> child[bits[i]] == NULL){
                root -> child[bits[i]] = new TrieNode();
            }
            root = root -> child[bits[i]];
        }
    }
    int findMaxXOR(TrieNode* root, vector<int> bits){
        
        ll maxxor = 0;
        for(int i = 0; i < bits.size(); i++){
            if(root -> child[1 - bits[i]]){
                maxxor += pow(2, 31 - i);
                root = root -> child[1 - bits[i]];
            }
            else{
                root = root -> child[bits[i]];
            }
        }
        return maxxor;
    }
    bool static cmp(vector<int> &v1, vector<int> &v2){
        return v1[1] < v2[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        TrieNode* root = new TrieNode();
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < queries.size(); i++){
            queries[i].push_back(i);
        }
        
        sort(queries.begin(), queries.end(), cmp);
        
        vector<int> res(queries.size(), - 1);
        
        int ind = 0;
        
        for(int i = 0; i < queries.size(); i++){
            int x = queries[i][0], m = queries[i][1], index = queries[i][2];
            while(ind < nums.size()){
                if(nums[ind] <= m){
                    insert(root, binary(nums[ind]));
                    ind++;
                }
                else{
                    break;
                }
            }
            if(ind == 0) res[index] = -1;
            else{
                int maxxor = findMaxXOR(root, binary(x));
                res[index] = maxxor;
            }
        }
        return res;
    }
};
