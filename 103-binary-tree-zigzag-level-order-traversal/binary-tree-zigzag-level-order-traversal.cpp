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
        vector<vector<int>> ans;

        if(root == nullptr){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        int ind = 0;
        while(!q.empty()){
            vector<int> level;
            int n = q.size();
            for(int i=0; i<n; i++){
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
            if(ind % 2 == 0){
                ans.push_back(level);
            }
            else{
                reverse(level.begin(), level.end());
                ans.push_back(level);
            }
            ind++;
        }
        return ans;
    }
};