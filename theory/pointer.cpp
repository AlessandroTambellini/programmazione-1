#include <iostream>

using namespace std;

int main()
{
    // non puoi cambiare il valore della variabile puntata dal puntatore.
    // Ma puoi cambiare l’indirizzo del puntatore
    const char *str1 = "ciao";

    // non puoi cambiare l’oggetto a cui il puntatore sta puntando
    char *const str2 = "ciao2";

    // non puoi cambiare né oggetto puntato né il valore di quest’ultimo
    const char *const str3 = "ciao3";

    // /* Priority */ //
    int *pv = new int(5);
    *pv + 1 == (*pv) + 1 != *(pv + 1);
    *pv++ == *(pv++) != (*pv)++;

    return 0;
}