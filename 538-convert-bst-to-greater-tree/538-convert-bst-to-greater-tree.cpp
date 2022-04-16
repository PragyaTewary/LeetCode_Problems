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

// sum = 8
// currr = 6
// root = 5
// 5
// 4
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        
        stack<TreeNode*> st;
        int sum = 0;
        TreeNode* res = root;
        while(root || !st.empty()){
            
            while(root){
                
                st.push(root);
                root = root->right;
            }
            
            TreeNode* curr = st.top();
            st.pop();
            
            sum += curr->val;
            curr->val = sum;
            
            root = curr->left;
        }
        
        return res;
    }
};