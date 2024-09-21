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
class Solution
{
private:
    void inorder(TreeNode *root, int &ans)
    {
        if (!root)
            return;

        inorder(root->left, ans);
        ans++;
        inorder(root->right, ans);
    }

public:
    int countNodes(TreeNode *root)
    {
        int ans = 0;
        if (!root)
            return 0;
        inorder(root, ans);
        return ans;
    }
};