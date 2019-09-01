#include <stdio.h>
// Create  Queue
#define Max_E 100
#define WHITE -1
#define BLUE 0
#define RED 1

int color[Max_E];
int conflict;
int cycle;

typedef int ElementType;
int mark[Max_E];
int parent[Max_E];
typedef struct
{
    ElementType data[Max_E];
    int size;
} List;

typedef struct
{
    int data[Max_E];
    int front, rear;
} Queue;
typedef struct
{
    int A[Max_E][Max_E];
    int n, m;
} Graph;
void make_null(List *L)
{
    L->size = 0;
}
/* Them mot phan tu vao cuoi danh sach */
void push_back(List *L, ElementType x)
{
    L->data[L->size] = x;
    L->size++;
}
/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 */
ElementType element_at(List *L, int i)
{
    return L->data[i - 1];
}
/* Tra ve so phan tu cua danh sach */
int count_list(List *L)
{
    return L->size;
}
void init_graph(Graph *g, int n, int m)
{
    int i, j;
    g->n = n;
    g->m = m;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            g->A[i][j] = 0;
        }
    }
}
void add_edge(Graph *g, int x, int y)
{
    g->A[x][y] = 1;
    g->A[y][x] = 1;
}
int adjacent(Graph *g, int x, int y)
{
    return g->A[x][y];
}

List neighbors(Graph *g, int x)
{
    List l;
    make_null(&l);
    int i;
    for (i = 1; i <= g->n; i++)
    {

        if (adjacent(g, x, i))
        {
            push_back(&l, i);
        }
    }
    return l;
}

void colorize(Graph* g, int x, int c) {
	if(color[x] == -1) {
		color[x] = c;
		List list = neighbors(g, x);
		int j, y;
		for(j = 1; j <= list.size; j++) {
			y = element_at(&list, j);
			if(color[y] == -1) {
				colorize(g, y, !c);
			} else if(color[y] == c) {
				conflict = 1;
				return;
			}
		}
	} else {
		if(color[x] == c) {
			conflict = 1;
		}
	}
}
int main()
{
    freopen("data4.txt", "r", stdin);
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    init_graph(&G, n, m);
    for (e = 1; e <= m; e++)
    {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    int j;
    for(j = 1; j <= n; j++) {
    	color[j] = -1;
	}
   	colorize(&G, 1, BLUE);
   
   	if(conflict == 1) {
   	return printf("IMPOSSIBLE");
   	}
    for(j = 1; j <= n; j++) {
    	if(color[j] == 0) {
    		printf("%d ", j);
		}
	}
	printf("\n");
	for(j = 1; j <= n; j++) {
    	if(color[j] == 1) {
    		printf("%d ", j);
		}
	}
	
	
}

