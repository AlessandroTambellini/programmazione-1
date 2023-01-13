#include <iostream>
#include <string.h> // definisce la funzione "int strlen (const char * array);"
#include <math.h>   // definisce la funzione "int pow (base, esponente);"
#include "pila.h"   // fare riferimento al file "pila.h" per le funzioni esposte

using namespace std;

int decodificaNumero(char numeroCodificato []);

int main() {
    int dimensioneMassima = 9;
    char numeroCodificato [dimensioneMassima];
    cout << "Inserisci l'array: ";
    cin >> numeroCodificato;
    int decodifica = decodificaNumero(numeroCodificato);
    cout << "Decodifica: " << decodifica << endl;
}

int decodificaNumero(char numeroCodificato []) {
    // Scrivere il codice qui

    // Potete assumere che l'array rispetti le assunzioni
    // dell'esercizio (non serve fare controlli sull'input)
  int numero = 0;
  int lencodifica = strlen(numeroCodificato);
  int esponente = lencodifica;
  init();
  for(int i = 0; i<= lencodifica; i++) {
    push(i+1);
    if (numeroCodificato[i] == 'I' ||
        i == lencodifica) {
      while(!vuota()) {
        int tmp;
        top(tmp);
        pop();
        numero = numero + tmp * pow(10, esponente);
        esponente--;
      }
    }
  }
  deinit();
  return numero;
}
