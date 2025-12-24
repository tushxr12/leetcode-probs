class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int minBoxes = 0;
        int totalApples = accumulate(begin(apple), end(apple), 0);

        sort(rbegin(capacity), rend(capacity));
        int curr = 0;
        for(int &i : capacity)
        {
            curr += i;
            minBoxes += 1;
            if(curr >= totalApples)
            {
                break;
            }
        }
        return minBoxes;
    }
};
