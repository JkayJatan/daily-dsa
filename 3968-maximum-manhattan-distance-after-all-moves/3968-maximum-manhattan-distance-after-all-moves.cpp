class Solution {
public:
    int maxDistance(string moves) {
        int x=0,y=0,z=0;
        for(char c:moves){
            if(c=='U')y++;
            else if(c=='D')y--;
            else if(c=='R')x++;
            else if(c=='L')x--;
            else z++;
        }
        return (abs(y)+abs(x)+z);
    }
};