#include <stdio.h>

#define MAX_VERTICES 100

// List
typedef struct {
    int data[MAX_VERTICES];
    int size;
} List;

void make_null_list(List* L) {
    L->size = 0;
}

void push_back(List* L, int x) {
    L->data[L->size] = x;
    ++L->size;
}

int element_at(List* L, int i) {
    return L->data[i - 1];
}

void copy_list(List* s1, List* s2) {
    make_null_list(s1);
    
    int i;
    for (i = 1; i <= s2->size; ++i) {
        push_back(s1, element_at(s2, i));
    }
}

// Queue
typedef struct {
    int data[100];
    int front, rear;
} Queue;

void make_null_queue(Queue* Q) {
    Q->front = 0;
    Q->rear = -1;
}

void push(Queue* Q, int x) {
    ++Q->rear;
    Q->data[Q->rear] = x;
}

int top(Queue* Q) {
    return Q->data[Q->front];
}

void pop(Queue* Q) {
    ++Q->front;
}

int empty(Queue* Q) {
    return Q->front > Q->rear;
}

// Graph
typedef struct {
    int A[MAX_VERTICES][MAX_VERTICES];
    int n;
} Graph;

void init_graph(Graph* G, int n) {
    G->n = n;

    int i, j;

    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            G->A[i][j] = 0;
        }
    }
}

void add_edge(Graph* G, int x, int y) {
    G->A[x][y] = 1;
}

int adjacent(Graph* G, int x, int y) {
    return G->A[x][y];
}

List neighbors(Graph* G, int x) {
    int y;
    List list;

    make_null_list(&list);

    for (y = 1; y <= G->n; ++y) {
        if (adjacent(G, x, y)) {
            push_back(&list, y);
        }
    }

    return list;
}

int rank[MAX_VERTICES];

void ranking(Graph* G) {
    int d[MAX_VERTICES];
    int x, u;
    Queue list;
    make_null_queue(&list);
    for (u = 1; u <= G->n; ++u) {
        d[u] = 0;
    }
    
    for (x = 1; x <= G->n; ++x) {
        for (u = 1; u <= G->n; ++u) {
            if (adjacent(G, x, u)) {
                ++d[u];
            }
        }
    }
    
    List s1, s2;
    
    make_null_list(&s1);
    
    for (u = 1; u <= G->n; ++u) {
        if (!d[u]) {
            push_back(&s1, u);
        }
    }
    
    int k = 1, i;
    
    while (s1.size) {
        make_null_list(&s2);
        
        for (i = 1; i <= s1.size; ++i) {
            int u = element_at(&s1, i);
            
            rank[u] = k;
            push(&list, u);
            
            int v;
            
            for (v = 1; v <=G->n; ++v) {
                if (adjacent(G, u, v)) {
                    --d[v];
                    
                    if (!d[v]) {
                        push_back(&s2, v);
                    }
                }
            }
        }
        
        copy_list(&s1, &s2);
        
        ++k;
    }
     while(!empty(&list)) {
		printf("%d ", top(&list));
		pop(&list);
	}
}

int main() {
	freopen("data2.txt", "r", stdin);
	Graph G;
	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	
	ranking(&G);
	return 0;
}
