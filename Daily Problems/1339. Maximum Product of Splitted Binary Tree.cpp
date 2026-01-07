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
    long long treeSum = 0;
    long long maxProd = 0;
    int mod = 1e9 + 7;
    
    int totSum(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int leftSubTree = totSum(root->left);
        int rightSubTree = totSum(root->right);
        int sum = root->val + leftSubTree + rightSubTree;

        return sum;
    }

    int find(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int leftSum = find(root->left);
        int rightSum = find(root->right);

        long long subtreeSum = root->val + leftSum + rightSum;
        long long remSubtreeSum = treeSum - subtreeSum;
        maxProd = max(maxProd, 1LL*subtreeSum*remSubtreeSum);

        return subtreeSum;
    }

    int maxProduct(TreeNode* root) {
        if(!root)
            return 0;

        maxProd = 0;
        treeSum = totSum(root);
        find(root);
        return (maxProd%mod);
    }
};
