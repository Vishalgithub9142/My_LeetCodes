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
    bool helper(TreeNode* currNodeLeft, TreeNode* currNodeRight){
        //if we reached leaf Node
        if(currNodeLeft== NULL && currNodeRight == NULL){
            return true;
        }

        if(currNodeLeft == NULL || currNodeRight == NULL){
            return false;
        }

        //If currNode is intermediate node
        if(currNodeLeft->val != currNodeRight->val){
            return false;
        }
        // Checking the subtrees: 
        // 1. Left node's left child with right node's right child
        // 2. Left node's right child with right node's left child
        return helper(currNodeLeft->left , currNodeRight->right)
        &&
        helper(currNodeLeft->right, currNodeRight->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return root==NULL || helper(root->left, root->right);
    }
};