## 有向图的搜索

### [有向图的API](DiGraph.cpp)

### [深度优先搜索](DirectedDFS.cpp)

### [深度优先搜索寻找路径](DepthFirstDirectedPaths.cpp)

### [广度优先搜索寻找路径](BreadthFirstDirectedPaths.cpp)

### [检查是否有环](DirectedCycle.cpp)

- 这里检查是否有环，使用的是模拟栈的方法，注意和无向图的区别。




## 基于DFS的拓扑排序

### DFS的顺序
  
  - 前序，就是在递归之前输出访问节点的信息
  - 后序，就是在递归之后输出访问节点的信息
  - 逆后续，就是后序逆置。

### 拓扑排序

  - 原图dfs得到后序，在逆后序中dfs。
  - 实现请参考“强联通分量分解”。
