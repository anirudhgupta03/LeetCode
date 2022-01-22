/*
Ref: https://leetcode.com/problems/water-and-jug-problem/discuss/1055738/VMware-asked-this-in-Interview.-My-BFS-solution-for-interview.
At any state (a,b) of the jugs we can do 6 things.
1) Pour contents of jug1 to jug2. (note that jug1 may still have some water left after pouring water to jug2)
2) Pour contents of jug2 to jug1. (note that jug2 may still have some water left after pouring water to jug1)
3) Empty jug1 completely.
4) Empty jug2 completely.
5) Fill jug1 completely (to its maximum limit)
6) Fill jug2 completely (to its maximum limit)
*/
class Solution {
public:
    #define pii pair<int,int>
    bool canMeasureWater(int x, int y, int z) {
        
        if(x + y == z) return true;
        if(x + y < z) return false;
        
        set<pair<int,int>> vis;
        queue<pair<int,int>> q;
        q.push({0,0});
        
        while(!q.empty()){
            
            pii p = q.front();
            q.pop();
            
            int currx = p.first, curry = p.second;
            
            if(currx + curry == z){
                return true;
            }
            
            if(vis.find({currx, curry}) != vis.end()){
                continue;
            }
            vis.insert({currx,curry});
            
            int newx, newy;
            
            //option1
            newx = currx - min(currx, y - curry);
            newy = curry + min(currx, y - curry);
            
            if(vis.find({newx, newy}) == vis.end()){
                q.push({newx, newy});
            }
            
            //option2
            newx = currx + min(curry, x - currx);
            newy = curry - min(curry, x - currx);
            
            if(vis.find({newx, newy}) == vis.end()){
                q.push({newx, newy});
            }
             
            //option3
            newx = 0;
            newy = curry;
            
            if(vis.find({newx, newy}) == vis.end()){
                q.push({newx, newy});
            }
             
            //option4
            newx = currx;
            newy = 0;
            
            if(vis.find({newx, newy}) == vis.end()){
                q.push({newx, newy});
            }
             
            //option5
            newx = x;
            newy = curry;
            
            if(vis.find({newx, newy}) == vis.end()){
                q.push({newx, newy});
            }
            
            //option6
            newx = currx;
            newy = y;
            
            if(vis.find({newx, newy}) == vis.end()){
                q.push({newx, newy});
            }
        }
        return false;
    }
};
