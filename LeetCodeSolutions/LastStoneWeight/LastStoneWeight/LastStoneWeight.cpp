class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());

        int max1;
        int max2;

        while (stones.size() > 1) {
            max1 = stones[0];
            stones.erase(stones.begin());
            make_heap(stones.begin(), stones.end());
            max2 = stones[0];
            stones.erase(stones.begin());
            stones.push_back(max1 - max2);
            make_heap(stones.begin(), stones.end());
        }

        return stones[0];
    }
};