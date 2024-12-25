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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int sz = q.size();
            vector<int> currLevel;
            for(int i = 0;i < sz;i++)
            {
                TreeNode* currNode = q.front();
                q.pop();
                if(currNode->left)
                    q.push(currNode->left);
                if(currNode->right)
                    q.push(currNode->right);
                currLevel.push_back(currNode->val);
            }
            sort(currLevel.begin(), currLevel.end());
            ans.push_back(currLevel[currLevel.size() - 1]);
        }
        return ans;
    }
};
