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
