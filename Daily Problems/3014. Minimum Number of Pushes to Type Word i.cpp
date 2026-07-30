class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        unordered_map<int,int> mpp;
        int ans = 0;

        int assignKey = 2;
        for(char &ch : word)
        {
            if(assignKey > 9)
            {
                assignKey = 2;
            }

            mpp[assignKey]++;
            ans += mpp[assignKey];

            assignKey++;
        }
        return ans;
    }
};
