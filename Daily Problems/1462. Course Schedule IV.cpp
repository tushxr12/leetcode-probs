class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> matrix(n , vector<bool>(n));
        for(int i = 0;i < prerequisites.size();i++)
        {
            int s = prerequisites[i][0];
            int d = prerequisites[i][1];
            matrix[s][d] = true;
        }

        for(int k = 0;k<n;k++)
        {
            for(int s = 0;s < n;s++)
            {
                for(int d = 0;d<n;d++)
                {
                    matrix[s][d] = matrix[s][d] || (matrix[s][k] && matrix[k][d]);
                }
            }
        }

        vector<bool> ans;
        for(int i = 0;i < queries.size();i++)
        {
            int s = queries[i][0];
            int d = queries[i][1];
            ans.push_back(matrix[s][d]);
        }
        return ans;
    }
};
