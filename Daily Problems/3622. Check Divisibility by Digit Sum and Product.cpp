class Solution {
public:
    long long findDigSum(int n)
    {
        long long sum = 0.0;
        string s = to_string(n);
        for(auto i : s)
            sum += (i-'0');
        return sum;
    }

    long long findDigProd(int n)
    {
        long long prod = 1.0;
        string s = to_string(n);
        for(auto i : s)
            prod *= (i-'0');
        return prod;
    }

    bool checkDivisibility(int n) {
        long long digSum = 0.0;
        long long digProd = 1.0;

        digSum = findDigSum(n);
        digProd = findDigProd(n);

        cout<<"Dig sum : "<<digSum<<" \nDig prod : "<<digProd<<"\n";
        return ((n%(digSum+digProd) == 0));
    }
};
