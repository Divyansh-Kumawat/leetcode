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
    bool check(TreeNode* root){
        TreeNode* temp=root;
        int rcnt=0,lcnt=0;
        while(temp!=0){
            temp=temp->left;
            lcnt++;
        }
        temp=root;
        while(temp!=0){
            temp=temp->right;
            rcnt++;
        }
        return abs(lcnt-rcnt)<=1;
    }
    bool isBalanced(TreeNode* root) {
        return check(root);
    }
};