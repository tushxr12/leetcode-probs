class Solution {
public:
    bool isRotationPossible(vector<int> &vec1, vector<int> &vec2)
    {
        vector<int> text = vec2;
        text.insert(end(text), begin(vec2), end(vec2));

        return KMPSearch(vec1, text);
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(begin(sorted), end(sorted));

        int ans = 0;

        for(int k = 1;k <= n;k++)
        {
            if(n%k != 0)
                continue;
            
            bool valid = true;
            for(int start = 0; start < n;start+=k)
            {
                vector<int> vec1(begin(nums) + start, begin(nums) + start + k);
                vector<int> vec2(begin(sorted) + start, begin(sorted) + start + k); 

                if(!isRotationPossible(vec1, vec2))
                {
                    valid = false;
                    break;
                }
            }

            if(valid)
                ans += k;
        }
        return ans;
    }
};
