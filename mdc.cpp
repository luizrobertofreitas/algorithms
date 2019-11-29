#include <iostream>

using namespace std;

int main() {
  int m, n;
  cout << "Digite o primeiro número:\n";
  cin >> m;
  cout << "Digite o segundo número:\n";
  cin >> n; 
 
  int min = m > n ? n : m;

  while (m % min != 0 || n % min != 0) min--;

  cout << "MDC: " << min << "\n";
}
