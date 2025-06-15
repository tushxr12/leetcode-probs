class Solution {
private:
    int square(int n)
    {
        int ans = 0;
        while(n)
        {
            ans += pow(n%10,2);
            n /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        //13 -> 1 + 9 -> 10
        //14->1 + 16 -> 17 -> 1 + 49 -> 50 -> 25 -> 49 -> 1625
        int slow = n, fast = n;

        do{ 
            slow = square(slow);
            fast = square(square(fast));
        }while(slow != fast);

        return (slow == 1);
    }
};
