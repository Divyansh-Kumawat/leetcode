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
     TreeNode* join(vector<int> &arr,int ub,int& i){
        if(i==arr.size() || arr[i]>ub) return NULL;
        TreeNode* root=new TreeNode(arr[i++]);
        root->left=join(arr,root->val,i);
        root->right=join(arr,ub,i);
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return join(preorder,INT_MAX,i);
    }
};