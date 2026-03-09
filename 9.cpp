class Solution {
    static const int P=1e9+7;
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector mem(zero+1,vector<vector<int>>(one+1,vector<int>(2,-1)));
        function<int(int,int,int)>dfs=[&](int i,int j,int k)->int{
            if(i<0||j<0){
                return 0;
            }
            if(i==0){
                return k==1&&j<=limit;
            }
            if(j==0){
                return k==0&&i<=limit;
            }
            int&res=mem[i][j][k];
            if(res==-1){
                if(k){
                    res=((dfs(i,j-1,0)+dfs(i,j-1,1))%P-dfs(i,j-1-limit,0)+P)%P;
                }
                else{
                    res=((dfs(i-1,j,0)+dfs(i-1,j,1))%P-dfs(i-1-limit,j,1)+P)%P;
                }
            }
            return res;
        };
        return (dfs(zero,one,1)+dfs(zero,one,0))%P;
    }
};