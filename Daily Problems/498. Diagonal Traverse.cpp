class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        map<int,vector<int>> mpp;
        vector<int> ans;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                mpp[i+j].push_back(mat[i][j]);
            }
        }

        for(auto i : mpp){
            for(auto j : i.second){
                cout<<j<<" ";
            }
        }

        bool flip = true;

        for(auto i : mpp){
            if(flip){
                reverse(i.second.begin(), i.second.end());
            }

            for(auto j : i.second){
                ans.push_back(j);
            }

            flip = !flip;
        }
        return ans;
    }
};
