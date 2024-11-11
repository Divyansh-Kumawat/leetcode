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
        TreeNode* temp=root;
        TreeNode* node=new TreeNode(val);
        if(root==NULL) return node;
        while(true){
            if(val>root->val){
                if(root->right==NULL){
                    root->right= node;
                    break;
                }
                root=root->right;
                
            }
            else if(val<root->val){
                if(root->left==NULL){ 
                    root->left=node;
                    break;
                }
                root=root->left;
                
                
            }
        }
        return temp;
        
    }
};