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
    TreeNode* first;
    TreeNode* mid;
    TreeNode* second;
    TreeNode* prev;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && root->val < prev->val) {  // violation
            if (!first) {
                first = prev;
                mid = root;
            } else {
                second = root;
            }
        }

        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = mid = second = prev = nullptr;
        inorder(root);

        if (second) {
            swap(first->val, second->val);
        } else {
            swap(first->val, mid->val);
        }
    }
};
