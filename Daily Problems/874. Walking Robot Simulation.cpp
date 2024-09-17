class Solution
{
public:
    static const int mul = 30001;
    int hashCordinates(int x, int y)
    {
        return (x + mul * y);
    }
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        unordered_set<int> st;
        for (auto i : obstacles)
            st.insert(hashCordinates(i[0], i[1]));

        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<int> currPosition = {0, 0};
        int maxDis = 0;
        int currDirection = 0;

        for (auto i : commands)
        {
            if (i == -1)
            {
                currDirection = (currDirection + 1) % 4;
                continue;
            }
            if (i == -2)
            {
                currDirection = (currDirection + 3) % 4;
                continue;
            }

            // Forward
            vector<int> direction = dirs[currDirection];
            for (int j = 0; j < i; j++)
            {
                int nextX = currPosition[0] + direction[0];
                int nextY = currPosition[1] + direction[1];
                if (st.find(hashCordinates(nextX, nextY)) != st.end())
                {
                    break;
                }
                currPosition[0] = nextX;
                currPosition[1] = nextY;
            }
            maxDis = max(maxDis, currPosition[0] * currPosition[0] + currPosition[1] * currPosition[1]);
        }
        return maxDis;
    }
};