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
    TreeNode* reverseOddLevels(TreeNode* root) {
        //Check if given root is null
        if(!root)
            return nullptr;
        
        queue<TreeNode*> q;
        q.push(root);

        int currLevel = 0;

        while(!q.empty())
        {
            int sz = q.size();
            vector<TreeNode*> currLevelNodes;

            //Traverse the current level
            for(int i = 0;i < sz;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                currLevelNodes.push_back(node);

                if(node->left)
                {
                    q.push(node->left);
                }

                if(node->right)
                {
                    q.push(node->right);
                }
            }

            //Check if current level is odd
            if(currLevel%2)
            {
                int left = 0, right = currLevelNodes.size() - 1;

                while(left < right)
                {
                    int temp = currLevelNodes[left]->val;
                    currLevelNodes[left]->val = currLevelNodes[right]->val;
                    currLevelNodes[right]->val = temp;
                    left++;
                    right--;
                }
            }
            currLevel++;
        }

        //Return modified root
        return root;
    }
};
