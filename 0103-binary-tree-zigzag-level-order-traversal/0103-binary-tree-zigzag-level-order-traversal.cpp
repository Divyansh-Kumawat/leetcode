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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // Determine the position to insert the node's value
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = node->val;
                
                // Enqueue child nodes in regular left-right order
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // After completing this level, switch the direction
            leftToRight = !leftToRight;
            ans.push_back(level);
        }
        
        return ans;
    }
};
