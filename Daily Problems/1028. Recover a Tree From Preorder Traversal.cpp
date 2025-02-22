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
    TreeNode* recur(string &traversal,int &index, int depth)
    {
        if(index >= traversal.size())
            return nullptr;
        
        int dashCount = 0;
        while(index + dashCount < traversal.size() && traversal[index + dashCount] == '-')
            dashCount++;
        
        if(dashCount != depth)
            return nullptr;
        
        index += dashCount;
        
        int val = 0;
        while(index < traversal.size() && isdigit(traversal[index]))
        {
            val = val*10 + (traversal[index] - '0');
            index++;
        }

        TreeNode* node = new TreeNode(val);
        node->left = recur(traversal, index, depth + 1);
        node->right = recur(traversal, index, depth + 1);

        return node;
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int index = 0;
        return recur(traversal, index, 0);
    }
};
