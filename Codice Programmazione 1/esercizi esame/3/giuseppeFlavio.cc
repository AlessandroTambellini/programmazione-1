#include <iostream>
#include "./queue.h"

using namespace std;

int findWinner(int players[], int playersNum, int jump);

int main(int argc, char *argv[])
{
    if (argc < 2 || argc > 3)
    {
        cout << "Usage: " << argv[0] << " <n> <m> " << endl;
        exit(1);
    }

    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    int a[N];
    for (int i = 0; i < N; i++)
    {
        a[i] = i + 1;
    }

    int winner = findWinner(a, N, M);

    cout << "Winner: " << winner << endl;

    return 0;
}

int findWinner(int players[], int playersNum, int jump)
{
    init();

    for (int i = 0; i < playersNum; i++)
    {
        enqueue(players[i]);
    }

    int n;
    int remainedPlayers = playersNum;
    while (remainedPlayers > 1)
    {
        for (int j = 0; j < jump - 1; j++)
        {
            first(n);
            dequeue();
            enqueue(n);
        }
        first(n);
        cout << "Deleted participant: " << n << endl;
        dequeue();
        remainedPlayers--;
    }

    first(n);
    deinit();

    return n;
}