class Solution {
private:
    int findDigitSum(int num)
    {
        int sum = 0;
        while(num > 0)
        {
            int ld = (num % 10);
            cout<<"LD : "<<ld<<"\n";
            sum += ld;
            num /= 10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0;i < n;i++){
            int sumOfCurrentDigits = findDigitSum(nums[i]);
            if(sumOfCurrentDigits == i)
                return i;
        }

        return -1;
    }
};
