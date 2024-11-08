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
