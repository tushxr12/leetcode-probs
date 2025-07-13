class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int m = players.size(), n = trainers.size();
        int i = 0, j =0, ans = 0;

        while(i < m && j < n)
        {
            if(players[i] > trainers[j])
            {
                j++;
            }
            else
            {
                ans++;
                i++;
                j++;
            }
        }
        return ans;
    }
};
