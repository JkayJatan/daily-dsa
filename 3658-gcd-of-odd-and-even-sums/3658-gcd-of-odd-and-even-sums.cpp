class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd=1,even=2;
        int oddsum=0,evensum=0;
        for(int i=0;i<n;i++){
            oddsum+=odd;
            evensum+=even;
            odd+=2;
            even+=2;
        }
        return gcd(oddsum,evensum);

    }
};