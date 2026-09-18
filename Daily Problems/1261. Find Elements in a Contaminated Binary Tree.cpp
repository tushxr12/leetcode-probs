class FindElements {
private:
    unordered_set<int> st;

    void recoverTree(TreeNode* root, int value)
    {
        if(!root)
            return;

        root->val = value;
        st.insert(value);

        if(root->left)
            recoverTree(root->left, 2*value + 1);
        if(root->right)
            recoverTree(root->right,2*value + 2);
    }
public:
    FindElements(TreeNode* root) {
        recoverTree(root,0);
    }
    
    bool find(int target) {
        return (st.count(target));
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
