// Approach-1
// TC -> O(LogN)
// SC -> O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        while(n%3 == 0){
            cout<<n<<" ";
            n /= 3;
        }
        return (n == 1);
    }
};

// Approach-2
// TC -> O(LogN)
// SC -> O(10
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        
        double x = log10(n)/log10(3);
        return x == (int)x;
    }
};

// Approach-3
// TC -> O(1)
// SC -> O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        // Max 32 bit power of 32
        double maxThreePowVal = pow(3,19);
        return (n > 0 && ((int)maxThreePowVal % n) == 0);
    }
};
