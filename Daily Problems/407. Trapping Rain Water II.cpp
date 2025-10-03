class Solution {
public:
    typedef pair<int, pair<int,int>> PP;

    vector<vector<int>> dirs = {{0,-1}, {0, 1}, {-1, 0}, {1,0}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<PP, vector<PP>, greater<>> boundaryCells; // min-head {height, {i,j}}

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Left most col & right most col (0, n - 1)
        for(int row = 0; row < m;row++){
            for(int col : {0, n - 1}){
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        // Top most row & bottom most row (0, m - 1)
        for(int col = 0; col < n;col++){
            for(int row : {0, m - 1}){
                boundaryCells.push({heightMap[row][col], {row, col}});
                visited[row][col] = true;
            }
        }

        int water = 0;

        while(!boundaryCells.empty()){
            PP bc = boundaryCells.top();
            boundaryCells.pop();

            int height = bc.first;
            int i = bc.second.first;
            int j = bc.second.second;

            // Find neighbors

            for(vector<int> & dir : dirs){
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]){
                    water += max(height - heightMap[i_][j_], 0);

                    boundaryCells.push({max(height, heightMap[i_][j_]) , {i_,j_}});

                    visited[i_][j_] = true;
                }
            }
        }
        return water;
    }
};
