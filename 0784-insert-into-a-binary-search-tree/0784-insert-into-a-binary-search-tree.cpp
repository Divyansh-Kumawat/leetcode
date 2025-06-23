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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* base=root;
        TreeNode* node=new TreeNode(val);
        int flag=1;
        if(root==NULL) return node;
        while(flag){
            if(val>base->val){
                if(base->right==NULL){
                    base->right=node;
                    flag=0;
                }
                base=base->right;
            }
            else if(val<base->val){
                if(base->left==NULL){
                    base->left=node;
                    flag=0;
                }
                base=base->left;
            }
        }
        
        return root;
    }
};