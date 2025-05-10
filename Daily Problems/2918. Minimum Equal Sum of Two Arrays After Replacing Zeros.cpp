class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long ans = INT_MIN;

        long long sum1 = 0,sum2 =0;
        long long zc1 = 0, zc2 = 0;

        for(auto i : nums1)
        {
            if(i == 0)
            {
                zc1++;
                sum1 += 1;
            }
            sum1 += i;
        }

        for(auto i : nums2)
        {
            if(i == 0)
            {
                zc2++;
                sum2 += 1;
            }   
            sum2 += i;
        }

        if(sum1 < sum2 && zc1 == 0)
            return -1;
        if(sum2 < sum1 && zc2 == 0)
            return -1;
        return max(sum1,sum2);
    }
};
