class NumberContainers {
private:
    map<int, set<int>> numberToIndex;
    map<int,int> indexToNumber;
public:
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if(indexToNumber.find(index) != indexToNumber.end())
        {
            int prevNumber = indexToNumber[index];
            numberToIndex[prevNumber].erase(index);
            if(numberToIndex[prevNumber].empty())
            {
                numberToIndex.erase(prevNumber);
            }
        }
        indexToNumber[index] = number;
        numberToIndex[number].insert(index); 
    }
    
    int find(int number) {
        if(numberToIndex.find(number) != numberToIndex.end())
        {
            return *numberToIndex[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
