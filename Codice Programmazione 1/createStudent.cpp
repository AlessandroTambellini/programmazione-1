#include <iostream>
#include <cstring>

using namespace std;

struct Studente
{
    char nome[20];
    char cognome[20];
    int matricola;
    float media;
};

Studente *genera_studente(char *nome, char *cognome, int matricola, float media)
{
    Studente *s = new Studente;
    s->matricola = matricola;
    s->media = media;
    strcpy(s->nome, nome);
    strcpy(s->cognome, cognome);
    return s;
}

void stampa_studente(Studente *s)
{
    cout << "Studente (matricola: " << s->matricola << ") :" << endl;
    cout << "\tNome: " << s->nome << endl;
    cout << "\tCognome: " << s->cognome << endl;
    cout << "\tMedia: " << s->media << endl;
}

int main(int argc, char *argv[])
{
    char nome[20] = "Alessandro";
    char cognome[20] = "Tambellini";
    Studente *mySelf = genera_studente(nome, cognome, 234611, 0);
    stampa_studente(mySelf);
    return 0;
}