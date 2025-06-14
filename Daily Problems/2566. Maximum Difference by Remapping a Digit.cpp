class Solution {
public:
    int minMaxDifference(int num) {
        string numInString = to_string(num);

        int idx = numInString.find_first_not_of('9');
        if(idx != string::npos)
        {
            char ch = numInString[idx];
            replace(numInString.begin(), numInString.end(), ch, '9');
        }

        string minNumber = to_string(num);
        char ch = minNumber[0];
        replace(minNumber.begin(), minNumber.end(), ch, '0');

        return (stoi(numInString) - stoi(minNumber));
    }
};
