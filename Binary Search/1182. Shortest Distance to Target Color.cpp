//https://www.goodtecher.com/leetcode-1182-shortest-distance-to-target-color/
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int q;
    cin >> q;
    
    vector<pair<int,int>> queries(q);
    int ind, col;
    
    for(int i = 0; i < q; i++){
        cin >> ind >> col;
        queries[i] = {ind, col};
    }
    
    vector<int> ind1, ind2, ind3;
    
    for(int i = 0; i < n; i++){
        if(arr[i] == 1) ind1.push_back(i);
        else if(arr[i] == 2) ind2.push_back(i);
        else if(arr[i] == 3) ind3.push_back(i);
    }
    
    vector<int> queriesans(q);
    
    for(int i = 0; i < q; i++){
        int tind = queries[i].first, tcol = queries[i].second;
        int jb = -1, ja = -1;
        
        if(tcol == 1){
            int lo = 0, hi = ind1.size() - 1;
            
            while(lo <= hi){
                int mid = (lo + hi)/2;
                if(ind1[mid] >= tind){
                    ja = ind1[mid];
                    hi = mid - 1;
                }
                else{
                    jb = ind1[mid];
                    lo = mid + 1;
                }
            }
        }
        else if(tcol == 2){
            int lo = 0, hi = ind2.size() - 1;
            
            while(lo <= hi){
                int mid = (lo + hi)/2;
                if(ind2[mid] >= tind){
                    ja = ind2[mid];
                    hi = mid - 1;
                }
                else{
                    jb = ind2[mid];
                    lo = mid + 1;
                }
            }
        }
        else if(tcol == 3){
            int lo = 0, hi = ind3.size() - 1;
            
            while(lo <= hi){
                int mid = (lo + hi)/2;
                if(ind3[mid] >= tind){
                    ja = ind3[mid];
                    hi = mid - 1;
                }
                else{
                    jb = ind3[mid];
                    lo = mid + 1;
                }
            }
        }
        if(ja != -1 && jb != -1){
            queriesans[i] = min(tind - jb, ja - tind);
        }
        else if(ja != -1){
            queriesans[i] = ja - tind;
        }
        else if(jb != -1){
            queriesans[i] = tind - jb;
        }
        else{
            queriesans[i] = -1;
        }
    }
    
    for(int i = 0; i < q; i++){
        cout << queriesans[i] << " ";
    }
    cout << endl;
}
