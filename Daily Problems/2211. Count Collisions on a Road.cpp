class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int i = 0, j = n - 1;

        while(i < n && directions[i] == 'L')
            i++;
        
        while(j >= 0 && directions[j] == 'R')
            j--;
        
        int collisions = 0;
        while(i <= j){
            if(directions[i] == 'L' || directions[i] == 'R')
                collisions++;
            i++;
        }
        return collisions;
    }
};
