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
private:
    int countSwaps(vector<int> &values)
    {
        int swaps = 0;
        vector<int> sorted = values;
        sort(sorted.begin(), sorted.end());

        unordered_map<int,int> mpp;
        for(int i = 0;i < values.size();i++)
            mpp[values[i]] = i;
        
        for(int i = 0;i < values.size();i++)
        {
            if(values[i] != sorted[i])
            {
                swaps++;
                int existingPos = mpp[sorted[i]];
                mpp[values[i]] = existingPos;
                mpp[sorted[i]] = i;
                swap(values[existingPos] , values[i]);
            }
        }
        return swaps;
    }
public:
    int minimumOperations(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);

        int swaps = 0;

        while(!q.empty())
        {
            int sz = q.size();
            vector<int> values(sz);

            for(int i =0;i < sz;i++)
            {
                TreeNode* currNode = q.front();
                q.pop();

                values[i] = currNode->val;
                if(currNode->left)
                    q.push(currNode->left);
                
                if(currNode->right)
                    q.push(currNode->right);
            }

            swaps += countSwaps(values);
        }
        return swaps;
    }
};
