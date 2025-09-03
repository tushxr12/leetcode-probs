class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;

        auto lambda = [](vector<int> &point1, vector<int> &point2){
            if(point1[0] == point2[0]){
                return point1[1] > point2[1];
            }

            return point1[0] < point2[0];
        };

        sort(begin(points), end(points), lambda);

        for(int i = 0;i < n;i++){
            //A
            int x1 = points[i][0];
            int y1 = points[i][1];

            int maxY = INT_MIN;

            // Find B
            for(int j = i + 1;j < n;j++){

                int x2 = points[j][0];
                int y2 = points[j][1];

                if(y2 > y1)
                    continue;
                
                if(y2 > maxY){
                    res++;
                    maxY = y2;
                }
            }
        }

        return res;
    }
};
