#include<stdio.h>
#define MAXN 500
#define NO_EDGE 0
#define INFINITY 999

// Graph
typedef struct {
	int n;
	int L[MAXN][MAXN];
}Graph;

void init_graph(Graph* G, int n) {
	G->n = n;
	int i, j;
	for(i = 1; i <= n; i++) 
		for(j = 1; j <= n; j++) {
			G->L[i][j] = NO_EDGE;
		}
}

void add_edge(Graph* G, int x, int y, int w) {
	G->L[x][y] = w;
//	G->L[y][x] = w;
}

int mark[MAXN];
int pi[MAXN];
int p[MAXN];

void Dijkstra(Graph* G, int s) {
	int i, j, it;
	for(i = 1; i <= G->n; i++) {
		pi[i] = INFINITY;
		mark[i] = 0;
	}
	
	pi[s] = 0;
	p[s] = -1;
	
	for(it = 1; it < G->n; it++) {
		int min_pi = INFINITY;
		for(j = 1; j <= G->n; j++) {
			if(mark[j] == 0 && pi[j] < min_pi) {
				min_pi = pi[j];
				i = j;
			}
		}
		
		mark[i] = 1;
		for(j = 1; j <= G->n; j++) {
			if(G->L[i][j] != NO_EDGE && mark[j] == 0) {
				if(pi[i] + G->L[i][j] < pi[j]) {
					pi[j] = pi[i] + G->L[i][j];
					p[j] = i;
				}
			}
		}
	}
}



int main() {
	//freopen("data2.txt", "r", stdin);
	int n, m, u, v, w, e;
	Graph G;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for(e = 1; e <= m; e++) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	
	Dijkstra(&G, 1);
	
//	if (pi[n] == INFINITY) {
//		printf("-1");
//	} else {
//		printf("%d", pi[n]);
//	}
	
	if(pi[n] != INFINITY) {
		printf("%d", pi[n]);
	} else {
		printf("%d", -1);
	}
//	printf("\n");
//	for(e = 1; e <= n; e++) {
//		printf("%d %d\n", e, pi[e]);
//	}
	
//	int path[100];
//	int k = 0;
//	int current = n;
//	while(current != -1) {
//		path[k] = current; k++;
//		current = p[current];
//	}
//	for(e = k -1 ; e >= 0; e--) {
//		printf("%d ", path[e]);
//	}
	return 0;
}
