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
        TreeNode* newNode=new TreeNode(val);
                if(root==NULL) return newNode;

        int flag=1;
        while(flag){
            if(val>base->val){
                if(base->right==NULL){
                    base->right=newNode;
                    flag=0;
                }
                base=base->right;
            }
            if(val<base->val){
                if(base->left==NULL){
                    base->left=newNode;
                    flag=0;
                }
                base=base->left;
            }
        }
        return root;
    }
};