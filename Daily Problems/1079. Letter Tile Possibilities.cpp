class Solution {
private:
    void backtrack(string tiles, vector<bool> &used, set<string> &st, string curr)
    {
        if(st.find(curr) != st.end())
            return;
        st.insert(curr);
        for(int i = 0;i < tiles.size();i++)
        {
            if(used[i])
                continue;
            used[i] = true;
            backtrack(tiles, used, st, curr + tiles[i]);
            used[i] = false;
        }
    }
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<bool> used(n, false);
        set<string> st;
        backtrack(tiles, used, st, "");
        return st.size() - 1;
    }
};
