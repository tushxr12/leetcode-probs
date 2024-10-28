class Solution
{
private:
    void solve(TreeNode *root, vector<int> &currPath, vector<vector<int>> &v)
    {
        if (!root)
            return;

        currPath.push_back(root->val);
        if (!root->left && !root->right)
            v.push_back(currPath);
        else
        {
            solve(root->left, currPath, v);
            solve(root->right, currPath, v);
        }
        currPath.pop_back();
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        if (!root)
            return ans;
        vector<int> currPath;
        vector<vector<int>> v;
        solve(root, currPath, v);
        for (auto i : v)
        {
            string curr = "";
            for (int j = 0; j < i.size(); j++)
            {
                if (j == i.size() - 1)
                {
                    curr += to_string(i[j]);
                }
                else
                {
                    curr += (to_string(i[j]) + "->");
                }
            }
            // for(auto j : i)
            // {
            //     curr += (to_string(j) + "->");
            // }
            ans.push_back(curr);
        }
        return ans;
    }
};
