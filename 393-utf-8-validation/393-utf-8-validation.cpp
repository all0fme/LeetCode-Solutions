class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        int i=0;
        int j=0;
        
        int n = data.size();
        while(i<n)
        {
            int mjbit =0;
            for(int bit=7;bit>=0;bit--)
            {
                if((1<<bit)&data[i])
                {
                    mjbit++;
                }
                else
                    break;
            }
           //cout<<data[i]<<" "<<mjbit<<"\n";
            if(mjbit>4 || mjbit==1)
                return false;
            else{
                
                j= mjbit;
            }
            
           
            if((i+j-1)>=n)
                return false;
            for(int k= i+1;k<i+j;k++)
            {
                //cout<<data[k]<<" \n";
                if(!(((1<<7)&data[k]) && !((1<<6)&data[k])))
                    return false;
            }
            if(j==0)
                i++;
            else
            i+=j;
        }
        return true;
        
    }
};