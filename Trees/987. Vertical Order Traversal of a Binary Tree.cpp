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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> res;
        if(root == NULL) return res;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        unordered_map<int, vector<int>> umap;

        int minLevel = 0, maxLevel = 0;

        while(!q.empty()){
            int sz = q.size();
            unordered_map<int, vector<int>> tmap;
            while(sz--){
                TreeNode* curr = q.front().first;
                int vLevel = q.front().second;
                tmap[vLevel].push_back(curr -> val);

                minLevel = min(minLevel, vLevel);
                maxLevel = max(maxLevel, vLevel);
                q.pop();

                if(curr -> left) q.push({curr -> left, vLevel - 1});
                if(curr -> right) q.push({curr -> right, vLevel + 1});
            }
            for(auto &x: tmap){
                vector<int> nodes = x.second;
                sort(nodes.begin(), nodes.end());
                for(int &node: nodes){
                    umap[x.first].push_back(node);
                }
            }
        }

        for(int i = minLevel; i <= maxLevel; i++){
            res.push_back(umap[i]);
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
        if(root == NULL) return res;

        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});

        map<int, map<int, multiset<int>>> mp;

        int minLevel = 0, maxLevel = 0;

        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int vLevel = q.front().second.first;
            int hLevel = q.front().second.second;
            q.pop();

            mp[vLevel][hLevel].insert(curr -> val);
            if(curr -> left) q.push({curr -> left, {vLevel - 1, hLevel + 1}});
            if(curr -> right) q.push({curr -> right, {vLevel + 1, hLevel + 1}});
        }

        for(auto p: mp){
            vector<int> nodes;
            for(auto q: p.second){
                nodes.insert(nodes.end(), q.second.begin(), q.second.end());
            }
            res.push_back(nodes);
        }
        return res;
    }
};
