#include <iostream>
#include <string>

using namespace std;

struct node {
    int val;
    node * next;
};

struct queue {
    node * head;
    node * tail;
};

void init(queue & q) {
    q.head = NULL;
};

bool enqueue(queue & q, int n ) {
    bool res = true;

    node * newNode = new (nothrow) node;
    if (newNode == NULL) res = false;
    else {
        newNode->next=NULL;
        newNode->val=n;

        if (q.head == NULL) {
            q.head = newNode;
        } else {
            q.tail ->next = newNode;
        }

        q.tail = newNode;
    }

    return res;
}

bool first(queue & q, int & n) {
    bool res = true;

    if (q.head == NULL) res = false;
    else n = q.head->val;

    return res;
}

bool dequeue(queue & q) {
    bool res = true;
    if (q.head == NULL) res = false;
    else {
        node * first = q.head;
        q.head = q.head->next;
        delete first;
    }

    return res;
}

void print(queue & q) {
    node * first = q.head;
    while (first != NULL)
    {
        cout << first -> val << " ";
        first = first->next;
    }
    cout << "\n";
}

void deinit(queue & q) {
    while (q.head != NULL)
    {
        node * first = q.head;
        q.head = q.head->next;
        delete first;
    }
}

string predictPartyVictory(string senate) {
    queue q;
    init (q);

    int contR=0, contD=0;

    //--RIEMPIO LA CODA--
    for (int i = 0; i < senate.length(); i++) {
        if (senate[i] == 'D') {
            enqueue(q,1);
            contD++;
        } else {
            enqueue(q,2);
            contR++;
        }
        
    }

    //-------------------
    int n;
    int dDaRim = 0, rDaRim = 0; 
    while(contR>0 && contD > 0) {
        first(q,n);
        if (n == 1) {
            dequeue(q);
            if (dDaRim == 0) {
                enqueue(q,n);
                rDaRim++;
            } else {
                dDaRim--;
                contD--;
            }
        } else {
            dequeue(q);
            if (rDaRim == 0) {
                enqueue(q,n);
                dDaRim++;
            } else {
                rDaRim--;
                contR--;
            }
        }

    }
    
    deinit(q);

    if (contD) return "Dire";
    else return "Radiant";


}

int main() {
    cout << predictPartyVictory("DDRRR");
}
