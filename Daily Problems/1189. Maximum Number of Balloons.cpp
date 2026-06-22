class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0, a = 0, l = 0, o = 0, n = 0;
    
        unordered_map<char,int> mpp;
        for(auto i : text)
        {
            mpp[i]++;
        }

        int mini = min({mpp['b'] , mpp['a'], mpp['l']/2, mpp['o']/2, mpp['n']});
        return mini;
    }
};
