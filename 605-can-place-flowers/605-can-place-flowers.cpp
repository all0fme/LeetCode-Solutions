class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ptr=0;
        int flr=0;
        while(ptr<flowerbed.size())
        {
            if(flowerbed[ptr]==1)
                ptr+=2;
            else
            {
                if(ptr==flowerbed.size()-1)
                    flr++,ptr++;
                else if(flowerbed[ptr+1]==0)
                    flr++,ptr++;
                 ptr++;
            }
            if(flr==n)
                return true;
        }
        return flr>=n;
        
    }
};