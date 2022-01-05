//https://www.codingninjas.com/codestudio/problems/hit-counter_1230785?leftPanelTab=0
class hitCounter
{
    public:
		vector<int> v;
        void hit(int timestamp)
        {
            v.push_back(timestamp);
        }

        int getHits(int timestamp)
        {
            int lo = 0, hi = v.size() - 1;
            int ind = -1;
            while(lo <= hi){
                int mid = (lo + hi)/2;
                if(v[mid] < timestamp - 300){
                    ind = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            return v.size() - ind - 1;
        }

};
