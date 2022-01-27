//Ref: https://www.youtube.com/watch?v=0lrBSK4wSxs
class Solution {
public:
    struct TrieNode{
        int count;
        TrieNode* child[2];
        TrieNode(){
            count = 0;
            for(int i = 0; i < 2; i++){
                child[i] = NULL;
            }
        }
    };
    vector<int> binary(int num){
        vector<int> v(32);
        for(int i = 31; i >= 0; i--){
            v[i] = num % 2;
            num /= 2;
        }
        return v;
    }
    void insert(TrieNode* root, vector<int> &bits){
        for(int i = 0; i < bits.size(); i++){
            if(root -> child[bits[i]] == NULL){
                root -> child[bits[i]] = new TrieNode();
            }
            root = root -> child[bits[i]];
            root -> count++;
        }
    }
    void findPairs(int ind, TrieNode* root, vector<int> &v, vector<int> &bits, int &cnt){
        
        if(ind == 32){
            cnt += root -> count;
            return;
        }
        if(root -> child[0]){
            int temp = -1;
            if(v[ind] == 0) temp = 0;
            else            temp = 1;
            
            if(temp == bits[ind]){
                findPairs(ind + 1, root -> child[0], v, bits, cnt);
            }
            else if(temp < bits[ind]){
                cnt += root -> child[0] -> count;
            }
        }
        if(root -> child[1]){
           int temp = -1;
            if(v[ind] == 0) temp = 1;
            else            temp = 0;
            
            if(temp == bits[ind]){
                findPairs(ind + 1, root -> child[1], v, bits, cnt);
            }
            else if(temp < bits[ind]){
                cnt += root -> child[1] -> count;
            } 
        }
    }
    int countPairs(vector<int>& nums, int low, int high) {
        
        TrieNode* root = new TrieNode();
    
        vector<int> v1 = binary(low - 1), v2 = binary(high);
        
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            vector<int> v = binary(nums[i]);
            int cnt1 = 0, cnt2 = 0;
            findPairs(0, root, v, v1, cnt1);
            findPairs(0, root, v, v2, cnt2);
            count += cnt2 - cnt1;
            insert(root, v);
        }  
        return count;
    }
};

//Optimization 
//Since the maximum number is 20000 which requires 15 bits so we can consider only 15 bits
class Solution {
public:
    struct TrieNode{
        int count;
        TrieNode* child[2];
        TrieNode(){
            count = 0;
            for(int i = 0; i < 2; i++){
                child[i] = NULL;
            }
        }
    };
    vector<int> binary(int num){
        vector<int> v(15);
        for(int i = 14; i >= 0; i--){
            v[i] = num % 2;
            num /= 2;
        }
        return v;
    }
    void insert(TrieNode* root, vector<int> &bits){
        for(int i = 0; i < bits.size(); i++){
            if(root -> child[bits[i]] == NULL){
                root -> child[bits[i]] = new TrieNode();
            }
            root = root -> child[bits[i]];
            root -> count++;
        }
    }
    void findPairs(int ind, TrieNode* root, vector<int> &v, vector<int> &bits, int &cnt){
        
        if(ind == 15){
            cnt += root -> count;
            return;
        }
        if(root -> child[0]){
            int temp = -1;
            if(v[ind] == 0) temp = 0;
            else            temp = 1;
            
            if(temp == bits[ind]){
                findPairs(ind + 1, root -> child[0], v, bits, cnt);
            }
            else if(temp < bits[ind]){
                cnt += root -> child[0] -> count;
            }
        }
        if(root -> child[1]){
           int temp = -1;
            if(v[ind] == 0) temp = 1;
            else            temp = 0;
            
            if(temp == bits[ind]){
                findPairs(ind + 1, root -> child[1], v, bits, cnt);
            }
            else if(temp < bits[ind]){
                cnt += root -> child[1] -> count;
            } 
        }
    }
    int countPairs(vector<int>& nums, int low, int high) {
        
        TrieNode* root = new TrieNode();
    
        vector<int> v1 = binary(low - 1), v2 = binary(high);
        
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            vector<int> v = binary(nums[i]);
            int cnt1 = 0, cnt2 = 0;
            findPairs(0, root, v, v1, cnt1);
            findPairs(0, root, v, v2, cnt2);
            count += cnt2 - cnt1;
            insert(root, v);
        }  
        return count;
    }
};
