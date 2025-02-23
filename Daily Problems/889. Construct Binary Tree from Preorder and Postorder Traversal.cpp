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
    map<int,int> mpp;
    TreeNode* recur(int i1,int i2,int j1,int j2, vector<int> &preorder, vector<int> &postorder)
    {
        if(i1 > i2 || j1 > j2)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[i1]);
        if(i1 == i2)
            return root;
        
        int r = mpp[preorder[i1 + 1]];
        int sz = r - j1 + 1;
        root->left = recur(i1 + 1, i1 + sz, j1, r,preorder,postorder);
        root->right = recur(i1 + sz + 1, i2, r + 1, j2 - 1, preorder, postorder);
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = postorder.size();
        for(int i = 0;i < n;i++)
        {
            mpp[postorder[i]] = i;
        }
        return recur(0,n-1,0,n-1,preorder,postorder);
    }
};
