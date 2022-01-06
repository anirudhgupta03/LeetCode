//https://xingxingpark.com/Leetcode-1060-Missing-Element-in-Sorted-Array/
//https://practice.geeksforgeeks.org/problems/k-th-missing-element3635/1/
int KthMissingElement(int a[], int n, int k)
{
    int ele = a[0];
    
    for(int i = 1; i < n; i++){
        if(a[i] - ele > k){
            return ele + k;
        }
        else{
            k -= (a[i] - ele - 1);
        }
        ele = a[i];
    }
    return -1;
}
