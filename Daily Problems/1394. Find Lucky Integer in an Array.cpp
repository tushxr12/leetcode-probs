class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mpp;
        int n = arr.size();
        for(int i = 0;i < n;i++)
            mpp[arr[i]]++;
        
        int ans = -1;
        for(auto i : mpp)
            if(i.first == i.second)
                ans = i.first;
            
        return ans;
    }
};
