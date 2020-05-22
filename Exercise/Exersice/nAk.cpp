//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//char letter[26]{
//    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'
//    , 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'
//    , 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
//};
//
//int main ()
//{
////    int N, K;
////    cin >> N >> K;
////    int idx = 0;
//    char ch[] = {'a', 'b', 'c'};
//    for (int i=0; i<20; i++){
//        cout << ch[i] << ch[i+1] << endl;
//        next_permutation(ch,ch+2);
//    }
//
//}

// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort

int main () {
  char myints[] = {'a', 'b', 'c'};

  std::sort (myints,myints+3);

  std::cout << "The 3! possible permutations with 3 elements:\n";
  do {
    std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
  } while ( std::next_permutation(myints,myints+2) );

  std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

  return 0;
}
