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
    TreeNode* createBinaryTree(vector<vector<int>>& des) 
    {
        unordered_map<int, TreeNode*> getNode;
        unordered_set<TreeNode*> isChild;
        int n = des.size();
        for(int i=0;i<n; i++)
        {
            int p = des[i][0];
            int c = des[i][1];
            int left = des[i][2];
            TreeNode* par = NULL;
            TreeNode* child = NULL;
            if(getNode.find(p) == getNode.end())
            {
                par = new TreeNode(p);
            }
            else
            {
                par = getNode[p];

            }
            if(getNode.find(c) == getNode.end())
            {
                child = new TreeNode(c);
            }
            else
            {
                child = getNode[c];
            }
            if(left)
            {
                par->left = child;
            }
            else
            {
                par->right = child;
            }
            getNode[p] = par;
            getNode[c] = child;
            isChild.insert(child);
        }
        
        for(auto node: getNode)
        {
            if(isChild.find(node.second) == isChild.end())
            {
                return node.second;
            }
        }
        return NULL;
    }
};