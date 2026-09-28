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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == nullptr){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* currNode = q.front();
                q.pop();

                if(currNode->left != nullptr){
                    q.push(currNode->left);
                }
                if(currNode->right != nullptr){
                    q.push(currNode->right);
                }
                level.push_back(currNode->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};