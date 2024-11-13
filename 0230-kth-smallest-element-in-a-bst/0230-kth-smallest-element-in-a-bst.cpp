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
    void inorder(TreeNode* root,int& counter,int k,int& ksmallest){
        if(!root || counter>=k) return ;
        inorder(root->left,counter,k,ksmallest);
        counter++;
        if(counter==k){
            ksmallest=root->val;
            return;
        }
        inorder(root->right,counter,k,ksmallest);

    }
    int kthSmallest(TreeNode* root, int k) {
        int counter=0;
        int ksmallest=INT_MIN;
        inorder(root,counter,k,ksmallest);
        return ksmallest;
    }
};