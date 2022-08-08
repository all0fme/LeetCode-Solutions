class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        int n = asteroids.size();
        
        for(int i=0;i<n;i++)
        {
            if(st.size()==0 || asteroids[i]>0)
            {
                st.push_back(asteroids[i]);
            }
            else{
                
                while(!st.empty() && st.back()>0 && st.back()<abs(asteroids[i]))
                {
                    st.pop_back();
                }
                if(st.size()==0|| st.back()<0)
                    st.push_back(asteroids[i]);
                else if(st.back()==abs(asteroids[i]))
                    st.pop_back();
            }
        }
        return st;
        
        
    }
};