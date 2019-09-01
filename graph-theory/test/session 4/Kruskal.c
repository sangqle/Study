#include<stdio.h>
#define MAXN 1000

// Graph
typedef struct {
    int u, v;
    int w;
} Edge;

typedef struct {
	int n, m;
	Edge edges[MAXN];
} Graph;

void init_graph(Graph* G, int n) {
	G->n = n;
	G->m = 0;
}

void add_edge(Graph* G, int u, int v, int w) {
    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    G->edges[G->m].w = w;
    ++G->m;
}

int parent[MAXN];

int findRoot(int u) {
	if(parent[u] == u) {
		return u;
	}
	return findRoot(parent[u]);
}

int Kruskal	 (Graph* G, Graph* T) {
	// sap xep cac cung cua do thi theo thu tu tang dan
	int i, j;
	for(i = 0; i < G->m; i++) {
		for(j = i + 1; j < G->m; j++) {
			if(G->edges[i].w > G->edges[j].w) {
				Edge tmp = G->edges[i];
				G->edges[i] = G->edges[j];
				G->edges[j] = tmp; 
			}
		}
	}
	
	// khoi tao T rong.
	init_graph(T, G->n);
	int u;
	for(u = 1; u <= G->n; u++) {
		parent[u] = u; // moi dinh la mot bo phan lien thong
	}
	
	// Duyt cat cugn cua G (Da sap xep)
	int e;
	int sum_w = 0;
	for(e = 0; e < G->m; e++) {
		int u = G->edges[e].u;
		int v = G->edges[e].v;
		int w = G->edges[e].w;
		
		int root_u = findRoot(u);
		int root_v = findRoot(v);
		
		if(root_u != root_v) {
			add_edge(T, u, v, w);
			// gop 2 bo phan lien thong lai
			parent[root_v] = root_u;
			sum_w += w;
		}
	}
	
	return sum_w;
}
int main() {
	freopen("data.txt", "r", stdin);
	Graph G, T;
	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for(e = 0; e < m; e++) {
		scanf("%d%d%d", &u, &v, &w);
		if(u > v) {
			int tmp = u;
			u = v;
			v = tmp;
		}
		add_edge(&G, u, v, w);
	}
	
	int sum_w = Kruskal(&G, &T);
	
	printf("%d\n", sum_w);
	
	for (e = 0; e < T.m; ++e) {
	    printf("%d %d %d \n", T.edges[e].u, T.edges[e].v, T.edges[e].w);
	}
	return 0;
}
