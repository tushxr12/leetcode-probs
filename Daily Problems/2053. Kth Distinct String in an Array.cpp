class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        string ans = "";
        map<string, int> mpp;
        for (auto i : arr)
        {
            mpp[i]++;
        }

        if (mpp.size() < k)
            return ans;
        int cnt = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            string curr = arr[i];
            if (mpp[curr] == 1 && cnt == k)
            {
                ans = curr;
                break;
            }
            if (mpp[curr] == 1)
                cnt++;
        }
        return ans;
    }
};