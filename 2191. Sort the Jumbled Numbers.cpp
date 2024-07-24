class Solution
{
public:
    void convertToMappingNumber(vector<int> &mapping, map<long long, vector<long long>> &mpp, int number)
    {
        string numberInString = to_string(number); // 991 -> "991"
        for (int i = 0; i < numberInString.size(); i++)
        {
            int number = numberInString[i] - '0';      // "9" -> 9
            numberInString[i] = mapping[number] + '0'; // numberInString[0] = mapping[9] -> 6
        }
        // After loop, numberInString variable would be entirely converted as per mapping array.
        // Ex: 991 -> 669, 338 -> 007, 38 -> 07 (As per 1st test case example given)

        int temp = stoi(numberInString); // temp = 669
        mpp[temp].push_back(number);     // 669 -> 991 (mpp[669] = [991], mpp[7] = [338, 38])
    }

    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        vector<int> ans;
        map<long long, vector<long long>> mpp;
        for (auto i : nums)
        {
            convertToMappingNumber(mapping, mpp, i);
        }

        for (auto i : mpp)
        {
            for (auto j : i.second)
            {
                ans.push_back(j);
            }
        }
        return ans;
    }
};