// TC -> O(1)
// SC -> O(1)
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int person1Diff = abs(x-z);
        int person2Diff = abs(y-z);

        if(person1Diff == person2Diff){
            return 0;
        }
        else if(person1Diff > person2Diff){
            return 2;
        }
        else
        {
            return 1;
        }
        return -1;
    }
};
