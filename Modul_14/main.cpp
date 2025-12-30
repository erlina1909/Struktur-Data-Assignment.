#include <iostream>
using namespace std;

struct ElmNode;
struct ElmEdge;

typedef ElmNode* adrNode;
typedef ElmEdge* adrEdge;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    char info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode CreateNode(char x) {
    adrNode p = new ElmNode;
    p->info = x;
    p->visited = 0;
    p->firstEdge = NULL;
    p->next = NULL;
    return p;
}

void InsertNode(Graph &G, char x) {
    adrNode p = CreateNode(x);
    if (G.first == NULL) {
        G.first = p;
    } else {
        adrNode q = G.first;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
}

adrNode FindNode(Graph G, char x) {
    adrNode p = G.first;
    while (p != NULL) {
        if (p->info == x)
            return p;
        p = p->next;
    }
    return NULL;
}

void ConnectNode(adrNode a, adrNode b) {
    adrEdge e1 = new ElmEdge;
    e1->node = b;
    e1->next = a->firstEdge;
    a->firstEdge = e1;

    adrEdge e2 = new ElmEdge;
    e2->node = a;
    e2->next = b->firstEdge;
    b->firstEdge = e2;
}

void ResetVisited(Graph &G) {
    adrNode p = G.first;
    while (p != NULL) {
        p->visited = 0;
        p = p->next;
    }
}

void DFS(adrNode p) {
    if (p == NULL || p->visited == 1)
        return;

    cout << p->info << " ";
    p->visited = 1;

    adrEdge e = p->firstEdge;
    while (e != NULL) {
        DFS(e->node);
        e = e->next;
    }
}

void BFS(adrNode start) {
    adrNode Q[20];
    int front = 0, rear = 0;

    start->visited = 1;
    Q[rear++] = start;

    while (front < rear) {
        adrNode p = Q[front++];
        cout << p->info << " ";

        adrEdge e = p->firstEdge;
        while (e != NULL) {
            if (e->node->visited == 0) {
                e->node->visited = 1;
                Q[rear++] = e->node;
            }
            e = e->next;
        }
    }
}

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G,'A');
    InsertNode(G,'B');
    InsertNode(G,'C');
    InsertNode(G,'D');
    InsertNode(G,'E');
    InsertNode(G,'F');
    InsertNode(G,'G');
    InsertNode(G,'H');

    ConnectNode(FindNode(G,'A'), FindNode(G,'B'));
    ConnectNode(FindNode(G,'A'), FindNode(G,'C'));
    ConnectNode(FindNode(G,'B'), FindNode(G,'D'));
    ConnectNode(FindNode(G,'B'), FindNode(G,'E'));
    ConnectNode(FindNode(G,'C'), FindNode(G,'F'));
    ConnectNode(FindNode(G,'C'), FindNode(G,'G'));
    ConnectNode(FindNode(G,'D'), FindNode(G,'H'));
    ConnectNode(FindNode(G,'E'), FindNode(G,'H'));
    ConnectNode(FindNode(G,'F'), FindNode(G,'H'));
    ConnectNode(FindNode(G,'G'), FindNode(G,'H'));

    cout << "DFS: ";
    ResetVisited(G);
    DFS(FindNode(G,'A'));

    cout << "\nBFS: ";
    ResetVisited(G);
    BFS(FindNode(G,'A'));

    return 0;
}