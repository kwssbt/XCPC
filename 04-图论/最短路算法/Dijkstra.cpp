给定起点，得到起点到每个点的最短距离
不能处理负边

普通堆实现
时间复杂度 O(MlogM)

const int N=1e5+5;
const int INF=0x3f3f3f3f;
// 堆里存：起点 -> cur 的距离为 cost
struct st{
    int cur;
    int cost;
};
// 边
struct e{
    int v,w;
};
vector<e>gra[N];
bool vis[N];
int dis[N]; // dis[v] : 起点 -> v 的最短距离
// 初始化
void init(int n){
    for(int i=1;i<=n;++i){
        gra[i].clear();
        dis[i]=INF;
        vis[i]=0;
    }
}
void dijkstra(int s){
    auto cmp=[](st a,st b){return a.cost>b.cost;};
    priority_queue<st,vector<st>,decltype(cmp)>pq(cmp);
    dis[s]=0;
    pq.push({s,0});
    while(pq.size()){
        auto [u,c]=pq.top();
        pq.pop();
        if(vis[u]==0){
            vis[u]=1;
            for(auto [v,w]:gra[u]){
                int nc=c+w;
                if(dis[v]>nc){
                    dis[v]=nc;
                    pq.push({v,nc});
                }
            }
        }
    }
}

反向索引堆实现
时间复杂度 O(MlogN)

const int N=1e5+5;
const int M=2e5+5;
const int INF=0x3f3f3f3f;
int dis[N];
 
//链式前向星建图
int tot;
int head[N];
int nex[M];
int to[M];
int val[M];
 
//手写堆
int heap[N];
int siz;
int tag[N];
//tag=-1 : 没有进过堆 (vis=0)
//tag=-2 : 已出堆结算 (vis=1)
//tag>=0 : 反向索引，指出在堆里的位置
 
void init(int n){
    tot=1;
    siz=0;
    for(int i=1;i<=n;++i){
        dis[i]=INF;
        head[i]=0;
        tag[i]=-1;
    }
}
void addEdge(int u,int v,int w){
    nex[tot]=head[u];
    to[tot]=v;
    val[tot]=w;
    head[u]=tot++;
}
void swap(int i,int j){
    int t=heap[i];
    heap[i]=heap[j];
    heap[j]=t;
    tag[heap[i]]=i;
    tag[heap[j]]=j;
}
void up(int i){
    while(dis[heap[(i-1)/2]]>dis[heap[i]]){
        swap(i,(i-1)/2);
        i=(i-1)/2;
    }
}
void down(int i){
    int l=i*2+1;
    while(l<siz){
        int best=l+1<siz&&dis[heap[l+1]]<dis[heap[l]]?l+1:l;
        if(dis[heap[i]]<=dis[heap[best]])return;
        swap(best,i);
        i=best;
        l=2*i+1;
    }
}
int pop(){
    int u=heap[0];
    swap(0,--siz);
    down(0);
    tag[u]=-2;
    return u;
}
void push(int v,int c){
    if(tag[v]==-2)return;
    if(tag[v]==-1){
        heap[siz]=v;
        tag[v]=siz++;
        dis[v]=c;
    }
    else dis[v]=min(dis[v],c);
    up(tag[v]);
}
void dijkstra(int s){
    push(s,0);
    while(siz){
        int u=pop();
        for(int ei=head[u];ei;ei=nex[ei]){
            push(to[ei],dis[u]+val[ei]);
        }
    }
}

