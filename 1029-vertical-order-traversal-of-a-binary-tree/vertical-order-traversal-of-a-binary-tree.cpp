class Solution {
    void find(TreeNode* root, int pos, int& l, int& r) {
        if (!root) return;
        l = min(l, pos);
        r = max(r, pos);
        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};

        int l = 0, r = 0;
        find(root, 0, l, r);

        // Store pairs of {row, value} so we can sort them later
        vector<vector<pair<int, int>>> negative(abs(l) + 1);
        vector<vector<pair<int, int>>> positive(r + 1);

        // Queue now stores {node, {col, row}}
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            
            TreeNode* node = temp.first;
            int col = temp.second.first;
            int row = temp.second.second;

            if (col >= 0) {
                positive[col].push_back({row, node->val});
            } else {
                negative[abs(col)].push_back({row, node->val});
            }

            if (node->left) {
                q.push({node->left, {col - 1, row + 1}});
            }
            if (node->right) {
                q.push({node->right, {col + 1, row + 1}});
            }
        }

        vector<vector<int>> ans;
        
        for (int i = negative.size() - 1; i > 0; i--) {
            if (!negative[i].empty()) {
                // Sort by row first, then by value
                sort(negative[i].begin(), negative[i].end());
                
                vector<int> col_vals;
                for (auto& p : negative[i]) {
                    col_vals.push_back(p.second);
                }
                ans.push_back(col_vals);
            }
        }

        for (int i = 0; i < positive.size(); i++) {
            if (!positive[i].empty()) {
                // Sort by row first, then by value
                sort(positive[i].begin(), positive[i].end());
                
                vector<int> col_vals;
                for (auto& p : positive[i]) {
                    col_vals.push_back(p.second);
                }
                ans.push_back(col_vals);
            }
        }

        return ans;
    }
};