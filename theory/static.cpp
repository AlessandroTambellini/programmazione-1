using namespace std;
#include <cstdlib>
#include <cstring>
#include <iostream>

void printChar() {
  static char a = 'a';
  cout << a << endl;
}

int numero = 0;

int f(int a) {
  cout << numero << ' ';
  static int numero = a;
  cout << ++numero << endl;
  int b = 30;
  return b;
}

int main() {
  f(numero);
  f(numero);
  f(numero);
  numero = 10;
  f(numero);
  f(numero);
  f(numero);
  int numero = 20;
  f(numero);
  f(numero);
  f(numero);
}

