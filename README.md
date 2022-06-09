## Graph Algos
### Bellman Ford Algorithm<br/>
Video Ref1: https://www.youtube.com/watch?v=FrLWd1tJ_Wc<br/>
Video Ref2: https://www.youtube.com/watch?v=24HziTZ8_xo
TC: O(VE)

Steps:
1) Initialize all vertices at dist = INT_MAX except source(0)
2) Relax all E edges V - 1 times
   -> if d(u) + cost(uv) < d(v) then d(v) = d(u) + cost(uv)
   -> else skip
3) Relax once more. If we find a new shortest path for any node then we have negative edge cycle, else we don't.

