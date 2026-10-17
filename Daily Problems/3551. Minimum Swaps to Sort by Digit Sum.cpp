class Solution {
public:

    int getDigitSum(int num)
    {
        int sum = 0;
        while(num)
        {
            sum += (num%10);
            num /= 10;
        }
        return sum;
    }
    
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);

        auto lambda = [&](int num1, int num2){
            int num1DigSum = getDigitSum(num1);
            int num2DigSum = getDigitSum(num2);

            if(num1DigSum != num2DigSum)
            {
                return num1DigSum < num2DigSum;
            }

            return num1 < num2;
        };

        sort(begin(sorted), end(sorted), lambda);
        unordered_map<int,int> valToIndex;
        for(int i = 0;i < n;i++)
        {
            valToIndex[nums[i]] = i;
        }

        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            int expectedVal = sorted[i];
            int curr = nums[i];

            if(expectedVal == curr)
                continue;
            
            int index = valToIndex[expectedVal];
            nums[i] = expectedVal;
            nums[index] = curr;
            valToIndex[expectedVal] = i;
            valToIndex[curr] = index;
            ans++;
        }
        return ans;
    }
};
