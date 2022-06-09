## Graph Algos
### Dijkstra's Algrorithm

### Bellman Ford Algorithm<br/>
Video Ref1: https://www.youtube.com/watch?v=FrLWd1tJ_Wc<br/>
Video Ref2: https://www.youtube.com/watch?v=24HziTZ8_xo<br/>
TC: O(VE)<br/>
SC: O(V)

Steps:
1) Initialize all vertices at dist = INT_MAX except source(0)
2) Relax all E edges V - 1 times<br/>
   -> if d(u) + cost(uv) < d(v) then d(v) = d(u) + cost(uv)
   -> else skip
3) Relax once more. If we find a new shortest path for any node then we have negative edge cycle, else we don't.

Problem1: https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0/?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU#<br/>
Code: https://github.com/anirudhgupta03/GFG/blob/main/Graph/Distance%20from%20the%20Source%20(Bellman-Ford%20Algorithm)%20.cpp<br/>

Problem1: https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1#<br/>
Code: https://github.com/anirudhgupta03/GFG/blob/main/Graph/Negative%20weight%20cycle%20-%20Using%20Bellman%20Ford%20Algorithm.cpp<br/>
