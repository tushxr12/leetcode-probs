class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> st(begin(word), end(word));
        int cnt = 0;
        vector<bool> visited(26, false);
        for(auto i : word)
        {
            if(i >= 'a' && i <= 'z')
            {
                char upper = toupper(i);
                if(!visited[i - 'a'] && st.find(upper) != st.end()){
                    cnt += 1;
                    visited[i-'a'] = true;
                }
            }
        }

        return cnt;
    }
};
