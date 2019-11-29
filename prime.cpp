#include <iostream>

using namespace std;

bool isPrime(int n) {
  bool flag = true;
  for (int i = 2 ; i < n ; i++) {
    if (n%i==0) {
      flag = false;
      break;
    }
  }
  return flag;
}

int main() {
  int n;
  cout << "Type a natural number:\t";
  cin>>n;

  cout << "Is prime? " << isPrime(n) << "\n";
}

