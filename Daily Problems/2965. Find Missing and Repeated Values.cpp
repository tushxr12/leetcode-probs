class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans(2);
        map<int,int> mpp;
        int sz = grid.size();
        vector<int> temp(sz*sz + 1);
        int k = 0;
        for(int i = 0;i < grid.size();i++)
        {
            for(int j = 0;j < grid[0].size();j++)
            {
                mpp[grid[i][j]]++;
                temp[k++] = (grid[i][j]);
            }
        }

        for(auto i : mpp)
            if(i.second == 2)
            {
                ans[0] = (i.first);
                break;
            }
        vector<int> hash(sz*sz + 1, 0);
        for(int i = 0;i <= sz*sz;i++)
        {
            hash[temp[i]] = 1;
        }
        cout<<"Hash : ";
        for(auto i : hash)
            cout<<i<<" ";
        cout<<endl;
        for(int i = 1;i <= sz*sz;i++)
        {
            // cout<<"Inside : "<<hash[i]<<endl;
            if(hash[i] == 0)
            {
                ans[1] = (i);
                break;
            }
        }
        return ans;
    }
};
