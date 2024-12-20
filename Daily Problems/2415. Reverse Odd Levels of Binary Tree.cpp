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


//DFS
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        traverseDFS(root->left, root->right, 0);
        return root;
    }

private:
    void traverseDFS(TreeNode* leftChild, TreeNode* rightChild, int level) {
        if (leftChild == nullptr || rightChild == nullptr) {
            return;
        }
        // If the current level is odd, swap the values of the children.
        if (level % 2 == 0) {
            int temp = leftChild->val;
            leftChild->val = rightChild->val;
            rightChild->val = temp;
        }

        traverseDFS(leftChild->left, rightChild->right, level + 1);
        traverseDFS(leftChild->right, rightChild->left, level + 1);
    }
};
