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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(root == nullptr) return ans;

        stack<TreeNode*> st;
        st.push(root);
        

        while(!st.empty()){

            TreeNode* currNode = st.top();
            st.pop();

            ans.push_back(currNode->val);

            //Pushing the right side FIRST to pop later in ans
            if(currNode->right != nullptr){
                st.push(currNode->right);
            }

            //pushing the left side later to push_back first in ans
            if(currNode->left != nullptr){
                st.push(currNode->left);
            }

        }        
        return ans;
    }
};