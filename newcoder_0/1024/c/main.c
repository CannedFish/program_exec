#include <stdio.h>

int gcd(int a, int b) {
  int t;
  if(a < 0) a = -a;
  if(b < 0) b = -b;
  while(b != 0) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}

void print_rational(long long int a, long long int b, long long int c) {
  if(c != 0) {
    c < 0 ? printf("(%lld", c) : printf("%lld", c);
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    if(a != 0) printf(" %lld/%lld", a, b);
    if(c < 0) printf(")");
  } else {
    if((a < 0 && b < 0) || (a > 0 && b < 0)) {
      a = -a;
      b = -b;
    }
    if(a < 0) printf("(");
    a != 0 ? printf("%lld/%lld", a, b) : printf("0");
    if(a < 0) printf(")");
  }
}

int main() {
  long long int a1, a1_, a2, a3, b1, b1_, b2, b3, c1, c2, c3, _gcd, a_gcd, b_gcd;
  scanf("%lld/%lld %lld/%lld", &a1_, &a2, &b1_, &b2);
  a_gcd = gcd(a1_, a2);
  a1_ /= a_gcd;
  a2 /= a_gcd;
  a3 = a1_ / a2;
  a1 = a1_ % a2;
  b_gcd = gcd(b1_, b2);
  b1_ /= b_gcd;
  b2 /= b_gcd;
  b3 = b1_ / b2;
  b1 = b1_ % b2;
  c2 = a2 * b2;

  print_rational(a1, a2, a3);
  printf(" + ");
  print_rational(b1, b2, b3);
  c1 = a1_*b2 + b1_*a2;
  c3 = c1/c2;
  c1 %= c2;
  _gcd = gcd(c2, c1);
  printf(" = ");
  print_rational(c1/_gcd, c2/_gcd, c3);
  printf("\n");

  print_rational(a1, a2, a3);
  printf(" - ");
  print_rational(b1, b2, b3);
  c1 = a1_*b2 - b1_*a2;
  c3 = c1 / c2;
  c1 %= c2;
  _gcd = gcd(c2, c1);
  printf(" = ");
  print_rational(c1/_gcd, c2/_gcd, c3);
  printf("\n");

  print_rational(a1, a2, a3);
  printf(" * ");
  print_rational(b1, b2, b3);
  c1 = a1_ * b1_;
  c3 = c1 / c2;
  c1 %= c2;
  _gcd = gcd(c2, c1);
  printf(" = ");
  print_rational(c1/_gcd, c2/_gcd, c3);
  printf("\n");

  print_rational(a1, a2, a3);
  printf(" / ");
  print_rational(b1, b2, b3);
  if(b1_ == 0) {
    printf(" = Inf\n");
  } else {
    c1 = a1_ * b2;
    c2 = a2 * b1_;
    c3 = c1 / c2;
    c1 %= c2;
    _gcd = gcd(c2, c1);
    printf(" = ");
    print_rational(c1/_gcd, c2/_gcd, c3);
    printf("\n");
  }
  return 0;
}
