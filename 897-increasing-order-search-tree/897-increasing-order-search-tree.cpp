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
    TreeNode* res = NULL;
    TreeNode* prev = NULL;
    void find(TreeNode* root){
        
        if(root == NULL){
            return;
        }
        
        find(root->left);

        if(prev != NULL){
            prev->right = root;
            
        }
        else{
            res = root;
        }
        prev = root;
        root->left =NULL;
        find(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        find(root);
        return res;
    }
};