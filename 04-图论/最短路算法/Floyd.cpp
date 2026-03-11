得到图中 任意两点 的最点距离
可处理负边，不能处理负环
时间复杂度 O(N^3) 

const int N=105;
const int INF=0x3f3f3f3f;
// dis[u][v] : u -> v 的距离
int dis[N][N];
// 初始化
void init(int n){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            dis[i][j]=INF;
        }
    }
}
void floyd(int n){
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
}