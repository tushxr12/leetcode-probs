class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp;
        unordered_set<int> childSet;

        for(vector<int> &description : descriptions)
        {
            int parent = description[0];
            int child = description[1];
            int isLeft = description[2];

            if(mpp.find(parent) == mpp.end())
            {
                mpp[parent] = new TreeNode(parent);
            }

            if(mpp.find(child) == mpp.end())
            {
                mpp[child] = new TreeNode(child);
            }

            if(isLeft)
            {
                mpp[parent]->left = mpp[child];
            }
            else
            {
                mpp[parent]->right = mpp[child];
            }

            childSet.insert(child);
        }

        for(auto &description : descriptions)
        {
            int parent = description[0];
            if(childSet.find(parent) == childSet.end())
                return mpp[parent];
        }
        return NULL;
    }
};
