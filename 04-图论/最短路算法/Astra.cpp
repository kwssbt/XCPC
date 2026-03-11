Astra

给定起点，给定终点，求两点间最短距离

Dijkstra + 预估函数 实现 启发式搜索

Astar 需要允许走回头路，相比 Dijkstra 删除 vis[] 机制

在堆中根据 从 起点 到 cur 的距离 + 从 cur 到 终点 的预估距离 进行排序

常用于网格图寻路：对实现预估函数友好

常用于抽象状态压缩

启发性算法讨论复杂度意义不大

预估函数
必须满足： 从 cur 到 终点 的预估距离 <= 从 cur 到 终点 的实际最短距离

预估距离 与 实际最短距离 越接近，启发性越好

常用预估方法（二维矩阵）

曼哈顿距离
int f1(int i,int j,int x,int y){
    return abs(x-i)+abs(y-j);
}

欧氏距离
//向下取整
int f2(int i,int j,int x,int y){
    return sqrt((x-i)*(x-i)+(y-j)*(y-j));
}
对角线距离
int f3(int i,int j,int x,int y){
    return max(abs(x-i),abs(y-j));
}