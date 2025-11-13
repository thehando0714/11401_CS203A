class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>vvt;
        vector<int>vt;
        vt.push_back(1);
        vvt.push_back(vt);
        for(int i=1;i<=rowIndex;i++){
            vector<int>tmp1(i+1);
            tmp1[0]=1;
            tmp1[i]=1;
            int ind=0;
            while(ind<i-1){
                tmp1[ind+1]=vvt[i-1][ind]+vvt[i-1][ind+1];
                ind++;
            }
            vvt.push_back(tmp1);
        }
        return vvt[rowIndex];
    }
};
