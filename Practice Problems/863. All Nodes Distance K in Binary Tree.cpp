class Solution
{
private:
    void mapParents(TreeNode *root, map<TreeNode *, TreeNode *> &parentMap)
    {
        if (!root)
            return;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *currNode = q.front();
            q.pop();

            if (currNode->left)
            {
                parentMap[currNode->left] = currNode;
                q.push(currNode->left);
            }

            if (currNode->right)
            {
                parentMap[currNode->right] = currNode;
                q.push(currNode->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        if (!root)
            return ans;

        map<TreeNode *, TreeNode *> parentMap;
        mapParents(root, parentMap);

        map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        int currLevel = 0;

        while (!q.empty())
        {
            if (currLevel++ == k)
                break;

            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *currNode = q.front();
                q.pop();

                if (currNode->left && !visited[currNode->left])
                {
                    q.push(currNode->left);
                    visited[currNode->left] = true;
                }

                if (currNode->right && !visited[currNode->right])
                {
                    q.push(currNode->right);
                    visited[currNode->right] = true;
                }

                if (parentMap[currNode] && !visited[parentMap[currNode]])
                {
                    q.push(parentMap[currNode]);
                    visited[parentMap[currNode]] = true;
                }
            }
        }
        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
