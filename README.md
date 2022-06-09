# Graph Algos
## Dijkstra's Algorithm<br/>
#### Shortest Path Algorithm
#### Given a graph, find shortest path from a source to all other vertices
#### Video Ref1: https://www.youtube.com/watch?v=t2d-XYuPfg0
#### Video Ref2: https://www.youtube.com/watch?v=t2d-XYuPfg0
#### TC: O(ElogV)
#### Limitation: It doesn't work for negative edge weight cycle
Steps:
1) Maintain a set of processed nodes.
2) Assign all nodes with distance = INT_MAX except source node(0).
3) Repeat following:-(unless all vertices are included)<br/>
   a) Pick min. value vertec which is not already processed.<br/>
   b) Include this selected node in processed set.<br/>
   c) Update all the adjacent node distances.<br/>
   d) if(new distance < old distance) then UPDATE<br/>
      else skip

## Bellman Ford Algorithm<br/>
#### Single Source Shortest Path
#### Video Ref1: https://www.youtube.com/watch?v=FrLWd1tJ_Wc<br/>
#### Video Ref2: https://www.youtube.com/watch?v=24HziTZ8_xo<br/>
#### TC: O(VE)<br/>
#### SC: O(V)<br/>

Dijkstra VS Bellman Ford
1) Dijkstra's Algorithm and Bellman Ford Algorithm does not find shortest path for graphs with negative edge weight cycles.
2) Dijkstra's Algorithm can't detect if graph has negative edge weight cycle while Bellman Ford Algorithm can.
3) Bellman Ford Algorithm will definitely work if all edges in undirected graph are positive.
4) Bellman Ford Algorithm does not find shortest path for undirected graph **if it has any negative edge**.


Steps:
1) Initialize all vertices at dist = INT_MAX except source(0)
2) Relax all E edges V - 1 times<br/>
   -> if d(u) + cost(uv) < d(v) then d(v) = d(u) + cost(uv)
   -> else skip
3) Relax once more. If we find a new shortest path for any node then we have negative edge cycle, else we don't.

Problem1: https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0/?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU#<br/>
Code: https://github.com/anirudhgupta03/GFG/blob/main/Graph/Distance%20from%20the%20Source%20(Bellman-Ford%20Algorithm)%20.cpp<br/>

Problem2: https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1#<br/>
Code: https://github.com/anirudhgupta03/GFG/blob/main/Graph/Negative%20weight%20cycle%20-%20Using%20Bellman%20Ford%20Algorithm.cpp<br/>

## Kruskal's Algorithm
#### Minimum Spanning Tree Algorithm
#### MST can be found for connected graph.
#### Kruskal's Algorithm is a greedy algorithm.
#### Video Ref1: https://www.youtube.com/watch?v=_Iz-QLBGKpM
#### Video Re2: https://www.youtube.com/watch?v=Ub-fJ-KoBQM

#### TC: O(ElogE  +  VlogV) 
          Sorting   DSU on V
          E edges   vertices
Steps:
1) Sort all the edges in non-decreasing order of their weight.
2) a) Pick the smallest edge.<br/>
   b) Check if the new edge forms a cycle in our spanning tree being formed(DSU).<br/>
   c) If cycle is not formed -> include the edge<br/>
      elese -> discard the edge<br/>
 
Problem: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1<br/>
Code: https://github.com/anirudhgupta03/GFG/blob/main/Graph/Minimum%20Spanning%20Tree%202.cpp<br/>

## Prims Algorithm
#### Minimum Spanning Tree Algorithm
#### Greedy Algorithm
#### MST can be found for connected graph.
#### Select min value option first.
#### Video Ref: https://www.youtube.com/watch?v=xthRL0lcx2w

#### TC: O(V*V)
Steps:
1) All node weights are INT_MAX except source.
2) Select node with min. weight(start at source).
3) Include selected node in set MST.
4) Relax/compute all adjacent edges.
 
Problem: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1<br/>
Code: https://github.com/anirudhgupta03/GFG/blob/main/Graph/Minimum%20Spanning%20Tree%201.cpp<br/>
