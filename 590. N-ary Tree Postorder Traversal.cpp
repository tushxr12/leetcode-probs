class Solution
{
public:
    void solve(Node *root, vector<int> &ans)
    {
        for (auto i : root->children)
            solve(i, ans);
        ans.push_back(root->val);
    }

    vector<int> postorder(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        solve(root, ans);
        return ans;
    }
};