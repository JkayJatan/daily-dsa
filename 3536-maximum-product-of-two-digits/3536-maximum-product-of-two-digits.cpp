class Solution {
public:
    int maxProduct(int n) {
        vector<int> freq(10, 0);
        while (n) {
            freq[n % 10]++;
            n /= 10;
        }

        int first = -1, second = -1;
        for (int i = 9; i >= 0; --i) {
            if (freq[i] == 0) continue;
            if (first == -1) {
                first = i;
                if (freq[i] >= 2) {   // digit repeats, can pair with itself
                    second = i;
                    break;
                }
            } else {
                second = i;
                break;
            }
        }
        return first * second;
    }
};