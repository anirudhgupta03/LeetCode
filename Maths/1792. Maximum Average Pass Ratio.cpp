#define pdi pair<double,int>
struct cmp{
    bool operator()(pdi &p1, pdi &p2){
        if(p1.first < p2.first){
            return true;
        }
        return false;
    }
};
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        priority_queue<pdi, vector<pdi>, cmp> pq;
        double res = 0;
        for(int i = 0; i < classes.size(); i++){
            if(classes[i][0] != classes[i][1]){
                pq.push({((1.0*(classes[i][0] + 1))/(classes[i][1] + 1) - (1.0*classes[i][0])/classes[i][1]), {i}});
            }
            res += (1.0*classes[i][0])/classes[i][1];
        }
        
        while(!pq.empty() && extraStudents--){
            pdi p = pq.top();
            pq.pop();
            double averagePass = p.first;
            res += averagePass;
            int index = p.second;
            classes[index][0]++;
            classes[index][1]++; 
            pq.push({((1.0*(classes[index][0] + 1))/(classes[index][1] + 1) - (1.0*classes[index][0])/classes[index][1]), {index}});
        }
        return res/classes.size();
    }
};
