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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if(!root)
            return res;
        stack<TreeNode*> ms;
        stack<TreeNode*> cs;
        ms.push(root);
        bool ltr = true;
        while(!ms.empty() || !cs.empty()){
            vector<int> pans;
            if(!ms.empty()){
                
                while(!ms.empty()){
                    
                    TreeNode* curr = ms.top();
                    pans.push_back(curr->val);
                    ms.pop();
                    if(ltr == true){
                         if(curr->left){
                            cs.push(curr->left);
                        }
                        if(curr->right){
                            cs.push(curr->right);
                        }
                    }
                    else{
                         if(curr->right){
                            cs.push(curr->right);
                        }
                         if(curr->left){
                            cs.push(curr->left);
                        }
                    }
                }
            }
            else{
                while(!cs.empty()){
                    
                    TreeNode* curr = cs.top();
                    pans.push_back(curr->val);
                    cs.pop();
                    if(ltr == true){
                         if(curr->left){
                            ms.push(curr->left);
                        }
                        if(curr->right){
                            ms.push(curr->right);
                        }
                    }
                    else{
                         if(curr->right){
                            ms.push(curr->right);
                        }
                         if(curr->left){
                            ms.push(curr->left);
                        }
                    }
                }
            }
            ltr = !ltr;
            //cout<<ltr<<" ";
            res.push_back(pans);
        }
        
        return res;
    }
};