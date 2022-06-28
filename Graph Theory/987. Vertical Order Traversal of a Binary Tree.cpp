//Method - 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    #define pipii pair<int,pair<int,int>>
    bool static cmp(pipii &p1, pipii &p2){
        if(p1.second.first == p2.second.first){
            if(p1.second.second == p2.second.second){
                return p1.first < p2.first;
            }
            return p1.second.second < p2.second.second;
        }
        return p1.second.first < p2.second.first;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,vector<pipii>> mp;
        
        queue<pair<TreeNode*,pipii>> q;
        q.push({root, {0,{0,0}}});
        
        while(!q.empty()){
            
            pair<TreeNode*,pipii> p = q.front();
            q.pop();
            
            TreeNode* curr = p.first;
            int level = p.second.first;
            int x = p.second.second.first, y = p.second.second.second;
            
            mp[level].push_back({curr -> val,{x,y}});
            
            if(curr -> left) q.push({curr -> left, {level - 1, {x + 1, y - 1}}});
            if(curr -> right) q.push({curr -> right, {level + 1, {x + 1, y + 1}}});
        }
        
        vector<vector<int>> res;
        
        for(auto &x: mp){
            vector<pipii> v = x.second;
            sort(v.begin(), v.end(), cmp);
            vector<int> temp;
            for(auto &y: v)
            temp.push_back(y.first);
            res.push_back(temp);
        }
        return res;
    }
};

//Method - 2
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> res;
        
        if(root == NULL){
            return res;
        }
        
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        
        map<int,vector<int>> mp;
        
        while(!q.empty()){
            int sz = q.size();
            unordered_map<int,map<int,int>> umap;
            while(sz--){
                TreeNode* curr = q.front().first;
                int level = q.front().second;
                
                q.pop();
                
                umap[level][curr -> val]++;
                
                if(curr -> left) q.push({curr -> left, level - 1});
                if(curr -> right) q.push({curr -> right, level + 1});
            }
            for(auto &x: umap){
                for(auto &y: x.second){
                    for(int i = 0; i < y.second; i++){
                        mp[x.first].push_back(y.first);
                    }
                }
            }
        }
        
        for(auto &x: mp){
            res.push_back(x.second);
        }
        return res;
    }
};
