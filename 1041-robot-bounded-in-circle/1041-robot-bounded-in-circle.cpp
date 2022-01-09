class Solution {
public:
    bool isRobotBounded(string instructions) {
        int disty =0,distx=0;
        int dir =0;
        for(char c: instructions)
        {
            if(c=='G')
            {
                if(dir==0)
                    disty++;
                else if(dir==1)
                    distx--;
                else if(dir==2)
                    disty--;
                else
                    distx++;
            }
            else if(c=='L')
            {
                dir+=1;
                dir%=4;
            }
            else
            {
                dir-=1;
                dir+=4;
                dir%=4;
            }
        }
        if((distx==0 && disty==0) || dir!=0)
            return true;
        return false;
    }
};