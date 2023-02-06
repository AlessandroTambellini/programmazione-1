#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    int d1a, d2a, d1b, d2b;
    matrix A;
    matrix B;
    matrix C;

    cout << "/* Create matrix A */\n";
    A = create_matrix(d1a, d2a);
    cout << "Matrix A:";
    print_matrix(A, d1a, d2a);

    cout << "/* Create matrix B */\n";
    B = create_matrix(d1b, d2b);
    cout << "Matrix B:";
    print_matrix(B, d1b, d2b);

    if (d1a == d1b && d2a == d2b)
    {
        C = sum(A, B, d1a, d2a);
        cout << "Matrice somma:";
        print_matrix(C, d1a, d2b);

        C = diff(A, B, d1a, d2a);
        cout << "Matrice differenza:";
        print_matrix(C, d1a, d2b);
    }

    if (d2a == d1b) // colonna x riga
    {
        C = product(A, B, d1a, d2a, d2b);
        cout << "Matrice prodotto:\n";
        print_matrix(C, d1a, d2b);
    }

    C = transpose(A, d1a, d2a);
    cout << "Matrice trasposta di A:";
    print_matrix(C, d1a, d2a);
}
