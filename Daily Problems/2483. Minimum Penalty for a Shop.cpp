class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int minHour = 0;
        int pen = count(begin(customers), end(customers), 'Y');
        int minPen = pen;

        for(int i = 0;i < n;i++){
            if(customers[i] == 'Y'){
                pen--;
            }
            else
            {
                pen++;
            }

            if(pen < minPen){
                minPen = pen;
                minHour = (i + 1);
            }
        }
        return minHour;
    }
};
