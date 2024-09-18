class Solution {
public:
    static bool comp(string &s1, string &s2)
    {
        return (s1 + s2) >= (s2 + s1);
    }
    string largestNumber(vector<int>& nums) {
        bool areAllZeroes = true;
        for(auto i : nums)
        {
            if(i != 0)
            {
                areAllZeroes = false;
                break;
            }
        }
        if(areAllZeroes)
        {
            return "0";
        }

        vector<string> numsInString;
        for(auto i : nums)
            numsInString.push_back(to_string(i));
        
        sort(numsInString.begin(), numsInString.end(), comp);
        string ans = "";
        for(auto i: numsInString)
            ans += i;
        return ans;
    }
};