/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent_mpp, TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            if(current->left){
                
                parent_mpp[current->left]=current;
                q.push(current->left);
            }
            if(current->right){
                
                parent_mpp[current->right]=current;
                q.push(current->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_mpp;
        markParent(root,parent_mpp,target);
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;
        q.push(target);
        visited[target]=true;        
        int curr_level=0;
        while(!q.empty()){
            int size=q.size();
            if(curr_level++==k) break;
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right]=true;
                }
                if(parent_mpp[current] && !visited[parent_mpp[current]]){
                    q.push(parent_mpp[current]);
                    visited[parent_mpp[current]]=true;
                }
            }            
        }
        vector<int> result;
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;
        
    }
};







