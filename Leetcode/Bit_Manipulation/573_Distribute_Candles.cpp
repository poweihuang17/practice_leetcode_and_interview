int distributeCandies(vector<int>& candies) {
        bitset<200001> hash;
        int count = 0;
        for (int i : candies) {
            if (!hash.test(i+100000)) {
               count++;
               hash.set(i+100000);
            }
        }
        int n = candies.size();
        return min(count, n/2);
    }

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        return min(unordered_set<int>(candies.begin(), candies.end()).size(), candies.size() / 2);
    }
};

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        size_t kinds = 0;
        sort(candies.begin(), candies.end());
        for (int i = 0; i < candies.size(); i++) {
            kinds += i == 0 || candies[i] != candies[i - 1];
        }
        return min(kinds, candies.size() / 2);
    }
};