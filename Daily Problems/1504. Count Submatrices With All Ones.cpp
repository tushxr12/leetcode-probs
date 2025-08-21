class Solution {
private:
    int oneDimArray(vector<int> &vec){
        int cons = 0, subCount =0;
        for(auto i : vec){
            if(i == 0)
                cons = 0;
            else
                cons++;
            subCount += cons;
        }
        return subCount;
    }
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int res = 0;
        for(int startRow = 0; startRow < n;startRow++)
        {
            vector<int> vec(m, 1);
            for(int endRow = startRow; endRow < n;endRow++){
                for(int col = 0; col < m;col++){
                    vec[col] &= mat[endRow][col];
                }

                res += oneDimArray(vec);
            }
        }
        return res;
    }
};
