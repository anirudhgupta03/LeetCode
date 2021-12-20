//https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/paint-fence-official/ojquestion
//Ref: https://www.youtube.com/watch?v=ju8vrEAsa3Q
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n ;
  cin >> n ;
  int k ;
  cin >> k ;

  long same = k;
  long diff = k*(k-1);
  long total = same + diff;
  
  for(int i = 3; i <= n; i++){
      same = diff;
      diff = total*(k-1);
      total = same + diff;
  }
  
  cout << total << endl;
}
