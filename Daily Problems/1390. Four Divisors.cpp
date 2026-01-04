class Solution {
private:
    int countDivisorsSum(int num)
    {
        int cnt = 0, sum = 0;
        for(int i = 1;i*i <= num;i++)
        {
            if(num%i == 0)
            {
                int otherDivisor = num/i;
                if(otherDivisor == i)
                {
                    cnt += 1;
                    sum += otherDivisor;
                }
                else
                {
                    cnt += 2;
                    sum += (i + otherDivisor);
                }
            }
            if(cnt > 4)
                return 0;
        }
        return (cnt == 4) ? sum : 0;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto i : nums)
            sum += countDivisorsSum(i);
        return sum;
    }
};
