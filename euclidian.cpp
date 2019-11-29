#include <iostream>

using namespace std;

int calculateMDC(int m, int n) {
  int min = m > n ? n : m;
  while (m % min != 0 || n % min != 0) min--;
  return min;
}

int main() {
  int a, b;
  cout << "Digite o primeiro número:\n";
  cin >> a;
  cout << "Digite o segundo número:\n";
  cin >> b;
  int m=0, n=1, mPrev=1, nPrev=0, mNext, nNext, mod=b, quot, modPrev=a, quotPrev, modNext, quotNext; 
 
  int mdc = calculateMDC(a, b);

  do { 
    modNext = modPrev % mod;
    quotNext = modPrev / mod;
    mNext = mPrev - (quotNext * m);
    nNext = nPrev - (quotNext * n);

    modPrev = mod;
    mod = modNext;
    quotPrev = quot;
    quot = quotNext;
    mPrev = m;
    m = mNext;
    nPrev = n;
    n = nNext;
    /* Debug lines
    cout << "modPrev: " << modPrev << ", mod: " << mod << ", modNext: " << modNext << "\n";
    cout << "quotPrev: " << quotPrev << ", quot: " << quot << ", quotNext: " << quotNext << "\n";
    cout << "mPrev: " << mPrev << ", m: " << m << ", mNext: " << mNext << "\n";
    cout << "nPrev: " << nPrev << ", n: " << n << ", nNext: " << nNext << "\n";
    cout << "----------------------------------------------------------\n";
    */
  } while (modNext != mdc);

  // Debug line
  //cout << "modNext: " << modNext << ", quotNext: " << quotNext << ", mNext: " << mNext << ", nNext: " <<nNext << "\n";
  cout << "------------------------------------------\n";
  cout << "Calculation... \n\n";
  cout << "\tm = " << mNext << ", n = " << nNext << "\n\n";
  cout << "\tMDC(" << a << ", " << b << ") = " << mdc << "\n\n";
  cout << "\t" << a << " * " << mNext << " + " << b << " * " << nNext << " = " << (a*m+b*n) << "\n";

  /*
   * Considering mdc(294, 108); a*m+b*n=mdc(294,108). Using Extended Euclidian Algorithm as:
   *
   * The calculation involves : 78 / 30 producing quotient = 2 and rest = 18; so: 
   *
   * Rj-1 / Rj = Qj + Rj  ==>   78/30 = 2 + 18 ==> 78 = 30 * 2 + 18
   *
   *
   *
   * Rest  Quotient     m      n      294 * m + 108 * n = mdc(294, 108)
   * 294   *            1      0      294 * 1 + 108 * 0 = 294
   * 108   *            0      1      294 * 0 + 108 * 1 = 108
   *  78   2            m1     n1     mj+1 = mj-1 + qj+1 * mj &&& nj+1 = nj-1 + qj+1 * nj
   *  30   1            m2     n2      
   *  18   2            mj-1   nj-1   rj-1  = a * mj-1  + b * nj-1
   *  12   1            mj     nj     rj    = a * mj    + b * nj
   *  6    1            mj+1   nj+1   rj+1  = a * mj+1  + b * nj+1 
   *  0    2
   *
   *  applying the formula:     rj-1 = rj * qj+1 + rj+1  where: 78 = 30 * 2 + 18
   *                            
   *                            rj+1 = rj-1 - qj+1 * rj    where: 18 = 78 - 2 * 30
   *
   *                            Decomposing the above formula:
   *
   *                            rj+1 = a * mj-1 + b * nj-1 - qj+1 * (a * mj + b * nj)
   *
   *                            Joining everything related to `a` and `b`
   *
   *                            rj+1 = a * (mj-1 - qj+1 * mj) + b * (nj-1 - qj+1 * nj)
   *
   *                            mj+1 = mj-1 - qj+1 * mj
   *                            nj+1 = nj-1 - qj+1 * nj
   *
   * doing the business: https://youtu.be/oRwuQrm3gqE?t=870
   */
}
