class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> colorMap, ballMap;
        vector<int> ans;
        for(auto i : queries)
        {
            auto query = i; //[1,4]
            int ball = query[0], color = query[1];

            if(ballMap.find(ball) == ballMap.end())
            {
                ballMap[ball] = color;
                colorMap[color]++;
            }
            else
            {
                int oldColor = ballMap[ball];
                colorMap[oldColor]--;
                if(colorMap[oldColor] == 0)
                {
                    colorMap.erase(oldColor);
                }
                ballMap[ball] = color;
                colorMap[color]++;
            }
            ans.push_back(colorMap.size());
        }
        return ans;
    }
};
