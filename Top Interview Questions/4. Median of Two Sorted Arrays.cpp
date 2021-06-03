//Method - 1 Using Merge Sort
//Time Complexity - O(n+m)
//Space Complexity - O(n+m)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size(); 
        
        vector<int> v(m+n);
        
        int p1 = 0, p2 = 0, i = 0;
        
        while(p1 < m && p2 < n){
            if(nums1[p1] < nums2[p2]){
                v[i] = nums1[p1];
                i++;
                p1++;
            }
            else{
                v[i] = nums2[p2];
                i++;
                p2++;
            }
        }
        
        while(p1 < m){
            v[i] = nums1[p1];
            i++;
            p1++;
        }
        while(p2 < n){
            v[i] = nums2[p2];
            i++;
            p2++;
        }
        
        if((m + n)%2 != 0){
            return v[(m+n)/2];
        }
        double e1 = v[(m+n)/2];
        double e2 = v[(m+n)/2-1];
        
        return (e1+e2)/2;
    }
};

//Method - 2
//Time Complexity - O(n+m)
//Space Complexity - O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size(); 
        
        double e1,e2;
        
        int p1 = 0, p2 = 0, i = 0;
        
        bool flag = false;
        
        while(p1 < m && p2 < n){
            if(nums1[p1] < nums2[p2]){
                
                if(i == (m+n)/2){
                    e2 = nums1[p1];
                    flag = true;
                    break;
                }
                if(i == (m+n)/2 - 1){
                    e1 = nums1[p1];
                }
                i++;
                p1++;
            }
            else{
                if(i == (m+n)/2){
                    e2 = nums2[p2];
                    flag = true;
                    break;
                }
                if(i == (m+n)/2 - 1){
                    e1 = nums2[p2];
                }
                i++;
                p2++;
            }
        }
        
        if(flag == false){
            while(p1 < m){
                if(i == (m+n)/2){
                    e2 = nums1[p1];
                    flag = true;
                    break;
                }
                if(i == (m+n)/2 - 1){
                    e1 = nums1[p1];
                }
                i++;
                p1++;
            }
            while(p2 < n){
                if(i == (m+n)/2){
                    e2 = nums2[p2];
                    flag = true;
                    break;
                }
                if(i == (m+n)/2 - 1){
                    e1 = nums2[p2];
                }
                i++;
                p2++;
            }
        }
        if((m + n)%2 != 0){
            return e2;
        }
        return (e1+e2)/2;
    }
};
//Method - 3
//Ref: https://www.youtube.com/watch?v=NTop3VTjmxk 
//Time Complexity - O(log(min(n1,n2))
//Space Complexity - O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size()){
            swap(nums1,nums2);
        }
        
        int n1 = nums1.size(), n2 = nums2.size();
        
        int lo = 0, hi = n1;
        
        int l1,l2,r1,r2;

        double e1,e2;
        
        while(lo <= hi){
            
            int cut1 = (lo+hi)/2;
            int cut2 =  (n1+n2+1)/2 - cut1;
                
            if(cut1 == 0) l1 = INT_MIN;
            else          l1 = nums1[cut1-1];
            
            if(cut2 == 0) l2 = INT_MIN;
            else          l2 = nums2[cut2-1];
            
            if(cut1 == n1) r1 = INT_MAX;
            else           r1 = nums1[cut1];
            
            if(cut2 == n2) r2 = INT_MAX;
            else           r2 = nums2[cut2];
            
            if(l1 <= r2 && l2 <= r1){
                e1 = max(l1,l2);
                e2 = min(r1,r2);
                break;
            }
            else if(l1 > r2){
                hi = cut1 - 1;
            }
            else{
                lo = cut1 + 1;
            }
        }
        
        if((n1+n2) % 2==0){
            return (e1+e2)/2;
        }
        return e1;
    }
};
