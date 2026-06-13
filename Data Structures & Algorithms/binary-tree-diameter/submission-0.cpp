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
    int diameter =0;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;    
    }
    int depth(TreeNode * node){
        if(node ==NULL){
            return 0;
        }
        int leftdepth = depth(node->left);
        int rightdepth = depth(node->right);
        diameter = max(diameter, leftdepth+rightdepth);
        return {1+max(leftdepth,rightdepth)};
    }
};
