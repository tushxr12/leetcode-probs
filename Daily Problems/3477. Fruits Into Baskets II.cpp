class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = 0;
        int n = fruits.size();
        int cnt = 0;

        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(fruits[i] <= baskets[j])
                {
                    baskets[j] = 0;
                    cnt++;
                    break;
                }
            }
        }
        return n - cnt;
    }
};
