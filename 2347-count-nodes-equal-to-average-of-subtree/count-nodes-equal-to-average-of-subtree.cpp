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

    pair<int, int> dfs(TreeNode* root, int &ans) {

        if (root == NULL)
            return {0, 0};

        // Get sum and count of left subtree
        auto left = dfs(root->left, ans);

        // Get sum and count of right subtree
        auto right = dfs(root->right, ans);

        // Current subtree
        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;

        // Check average
        int avg = sum / cnt;

        if (root->val == avg)
            ans++;

        // Return sum and count to parent
        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {

        int ans = 0;

        dfs(root, ans);

        return ans;
    }
};