class Solution {
public:
    int hIndex(vector<int>& ci) {

        if(ci.size()==1) return ci[0]>0? 1:0;
        sort(ci.begin(), ci.end(), greater<int>());

        int mn = INT_MAX, c =0, h=0;

        for(int i=0;i<ci.size();i++)
        {
            
            mn =min (mn, ci[i]);
            c++;
            if(mn >= c) h++;
            

        }
        return h;
        
    }
};