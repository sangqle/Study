#include<stdio.h>
#define MAX_VERTICES 100
#define oo 99

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

// Queue
typedef struct
{
    int data[100];
    int front, rear;
} Queue;

void make_null_queue(Queue *Q)
{
    Q->front = 0;
    Q->rear = -1;
}

void push(Queue *Q, int x)
{
    ++Q->rear;
    Q->data[Q->rear] = x;
}

int top(Queue *Q)
{
    return Q->data[Q->front];
}

void pop(Queue *Q)
{
    ++Q->front;
}

int empty(Queue *Q)
{
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

void copy_list(List* s1, List* s2) {
	make_null_list(s1);
	int i;
	for(i = 1; i <= s2->size; i++) {
		push_back(s1, element_at(s2, i));
	}
	
}

int min(int a, int b) {
	return a < b ? a : b;
}
int max(int a, int b) {
	return a > b ? a : b;
}

int rank[MAX_VERTICES];
//void topo_sort(Graph *G, List* l)
//{
//    int d[MAX_VERTICES];
//    int x, u;
//
//    for (u = 1; u <= G->n - 2; ++u)
//    {
//        d[u] = 0;
//    }
//
//    for (x = 1; x <= G->n -2; ++x)
//    {
//        for (u = 1; u <= G->n -2; ++u)
//        {
//            if (adjacent(G, x, u))
//            {
//                ++d[u];
//            }
//        }
//    }
//    Queue q;
//    make_null_list(l);
//    make_null_queue(&q);
//
//    for (u = 1; u <= G->n -2; ++u)
//    {
//        if (!d[u])
//        {
//            push(&q, u);
//        }
//    }
//
//    int i;
//
//    while (!empty(&q))
//    {
//        int u = top(&q);
//        pop(&q);
//
//        push_back(l, u);
//
//        List list = neighbors(G, u);
//
//        for (i = 1; i <= list.size; ++i)
//        {
//            int v = element_at(&list, i);
//
//            if (d[v] >= 0)
//            {
//                --d[v];
//            }
//
//            if (!d[v])
//            {
//                push(&q, v);
//            }
//        }
//    }
//}


void topo_sort(Graph* G, List* L) {
	make_null_list(L);
    int d[MAX_VERTICES];
    int x, u;
    
    for (u = 1; u <= G->n - 2; ++u) {
        d[u] = 0;
    }
    
    for (x = 1; x <= G->n -2; ++x) {
        for (u = 1; u <= G->n -2; ++u) {
            if (adjacent(G, x, u)) {
                ++d[u];
            }
        }
    }
    
    List s1, s2;
    
    make_null_list(&s1);
    
    for (u = 1; u <= G->n -2; ++u) {
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
            push_back(L, u);
            
            int v;
            
            for (v = 1; v <=G->n - 2; ++v) {
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
}

int d[MAX_VERTICES];
int T[MAX_VERTICES];
int t[MAX_VERTICES];
int main() {
	
	freopen("duanxaynha.txt", "r", stdin);
	// 1. Doc do thi
	Graph G;
	List L;
	int n, u, x, v, j;
	scanf("%d", &n);
	init_graph(&G, n + 2);
	d[n+1] = 0;
	
	for(u = 1; u <= n; u++) {
		scanf("%d", &d[u]); // Thoi gian hoan thanh cong viec u.
		do {
			scanf("%d", &x);
			if(x > 0) add_edge(&G, x, u); // them cung x -> u vao do thi
		} while(x > 0);
	}
	
	// 2. Them cung noi alpha voi cac dinh co bac vao = 0
	for(u = 1; u <= n; u++) {
		int deg_neg = 0;
		for(x = 1; x <= n; x++) {
			if(G.A[x][u] > 0) {
				deg_neg++;
			}
		}
		if(deg_neg == 0) {
			add_edge(&G, n+1, u); // dinh alpha la dinh n+1.
		}
	}
	
	// 3. Them cung noi cac dinh co bat ra = 0 voi beta
	for(u = 1; u <= n; u++) {
		int deg_pos = 0;
		for(v = 1; v <= n; v++) {
			if(G.A[u][v] > 0) {
				deg_pos++;
			}
		}
		if(deg_pos == 0) {
			add_edge(&G, u, n+2); // dinh beta la dinh n+2
		}
	}
	
	// 4. Xep thu tu topo va luu vao trong L
	topo_sort(&G, &L);
	
	for(u = 1; u <= L.size; u++) {
		printf("%d\n", element_at(&L, u));
	}
	// 5. Tinh t[u]
	int t[MAX_VERTICES];
	t[n+1] = 0; // t[alpha]  = 0;
	for(j = 2; j <= L.size; j++) {
		int u = element_at(&L, j);
		t[u] = oo; // vo cung
		for(x = 1; x <= G.n; x++) {
			if(G.A[x][u] > 0) {
				t[u] = min(t[u], t[x] + d[x]);
			}
		}
	}
	
	// 6. Tinh T[u]
	
	T[n+2] = t[n+2];
	for(j = L.size -1; j >= 1; j--) {
		int u = element_at(&L, j);
		t[u] = -1;
		for(v = 1; v <= G.n; v++) {
			if(G.A[u][v] > 0) {
				T[u] = max(T[u], T[u] - d[u]);
			}
		}
	}
	
	// 7. In t[u] va T[u] ra mang hinh
	int i;
	for(i = 1; i <= G.n; i++) {
		printf("t[%d] = %d, T[%d] = %d\n", i, t[i], i, T[i]);
	}

	return 0;
}
