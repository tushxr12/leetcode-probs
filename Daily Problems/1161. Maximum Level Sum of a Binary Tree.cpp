class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN, maxLevel = 0;

        queue<TreeNode*> q;
        q.push(root);

        int currLevel = 1;

        while(!q.empty())
        {
            int sz = q.size();
            int currSum = 0;

            while(sz--)
            {
                auto curr = q.front();
                q.pop();

                currSum += curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }

            
            if(currSum > maxSum)
            {
                maxSum = currSum;
                maxLevel = currLevel;
            }
            currLevel++;
        }

        return maxLevel;
    }
};
