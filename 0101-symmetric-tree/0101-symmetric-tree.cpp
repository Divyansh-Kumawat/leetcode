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
    bool check(TreeNode* node1,TreeNode* node2){
        if(node1==nullptr && node2==nullptr) return true;
        if(node1==nullptr || node2==nullptr) return false;
        return (node1->val==node2->val)&& check(node1->left,node2->right) && check(node1->right,node2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return true;
        return check(root->left,root->right); 
    }
};