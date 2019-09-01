#include <stdio.h>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <fstream>
#include <sstream>
#include <functional>

using namespace std;

const int BOARD_ROWS = 3;
const int BOARD_COLS = 3;
const int EMPTY_TITLE = 0;
const int MAX_OP = 4;
const double NANO_SEC = 1000000.0;

struct State {
	int num[BOARD_ROWS][BOARD_COLS];
	int empty_row;
	int empty_col;
};

struct Node {
	State state;
	Node* parent;
	int g; // Luu gia tri duong di cua nut goc den nut hien tai
	int h; // Luu gia ket qua uoc luong cua ham heuristic cua nut hien tai den trang thai dich
	int f; // = h + g
};

// Dung cho multimap de xac dinh vi tri phan tu dua vao
struct node_cmp {
	bool operator() (Node* a, Node* b) {
		return a->f < b->f;
	}
};

bool up(State s, State &out) {
	int er = s.empty_row, ec = s.empty_col;
	if (er > 0)	 {
		out = s;
		out.empty_col = ec;
		out.empty_row = er - 1;
		
		out.num[er][ec] = s.num[er-1][ec];
		out.num[er-1][ec] = EMPTY_TITLE;
		
		return true;
	}
	
	return false;
}

bool down(State s, State &out) {
	int er = s.empty_row, ec = s.empty_col;
	if (er < 3)	 {
		out = s;
		out.empty_col = ec;
		out.empty_row = er + 1;
		
		out.num[er][ec] = s.num[er+1][ec];
		out.num[er-1][ec] = EMPTY_TITLE;
		
		return true;
	}
	
	return false;
}

bool left(State s, State &out) {
	int er = s.empty_row, ec = s.empty_col;
	if (ec > 0)	 {
		out = s;
		out.empty_col = ec - 1;
		out.empty_row = er;
		
		out.num[er][ec] = s.num[er][ec-1];
		out.num[er-1][ec] = EMPTY_TITLE;
		
		return true;
	}
	
	return false;
}

bool right(State s, State &out) {
	int er = s.empty_row, ec = s.empty_col;
	if (ec < 3)	 {
		out = s;
		out.empty_col = ec + 1;
		out.empty_row = er;
		
		out.num[er][ec] = s.num[er][ec+1];
		out.num[er-1][ec] = EMPTY_TITLE;
		
		return true;
	}
	
	return false;
}

/**
* operator overload = compare 2 states are equal or not
**/
bool operator == (State s1, State s2) {
	if (s1.empty_col != s2.empty_col || s1.empty_row != s2.empty_row) {
		return false;
	}
	for (int row = 0; row < BOARD_ROWS; row++) {
		for (int col = 0; col < BOARD_COLS; col++) {
			if (s1.num[row][col] != s2.num[row][col]) {
				return false;
			}
		}
	}
}


/**
* Helper function, use to call operator base on operator no (1- 4) 
**/
bool call_operator(State s, State &out, int op_no) {
	switch (op_no) {
		case 1:
			return up(s, out);
		case 2: 
			return down(s, out);
		case 3:
			return left(s, out);
		case 4:
			return right(s, out);
		default:
			return false;
	}
}

void print_state(State s) {
	for (int i = 0; i < BOARD_ROWS; i++) {
		for (int j = 0; j < BOARD_COLS; j++) {
			printf("%d    ", s.num[i][j]);
		}
		printf("\n");
	}
}

/**
* Check if state is goal state or not
**/
bool is_goal(State s, State goal) {
	return s == goal;
}

/**
* H1 heutistic
**/
int h1(State s, State s2) {
	int count = 0;
	for (int row = 0; row < BOARD_ROWS; row++) {
		for (int col = 0; col < BOARD_COLS; col++) {
			if (s.num[row][col] != s2.num[row][col]) {
				count++;
			}
		}
	}
	
	return count;
}

Node* find_node(State s, multiset<Node *, node_cmp> list) {
	for (Node* n : list) {
		if (n->state == s) {
			return n;
		}
	}
	
	return NULL;
}

bool find_state(State s, vector <State> *explored) {
	for (State cl : *explored) {
		if (s == cl) {
			return true;
		}
	}
	
	return NULL;
}

Node* BFS(State init_state, State goal_state, vector<State> *explored,
			function<int (State, State)> heuristic) {
				
	// initial 
	Node* root = new Node();
	root->state = init_state;
	root->parent = NULL;
	root->g = 0;
	root->h = h1(init_state, goal_state);
	root->f = root->g + root->h;
	//Open list
	multiset<Node *, node_cmp> frontiers;
	frontiers.insert(root);
	while (!frontiers.empty()) {
		Node* node = *frontiers.begin();
		frontiers.erase(frontiers.begin());
		explored->push_back(node->state);
		if(is_goal(node->state, goal_state)) {
			return node;
		}
		
		cout <<  "Do sau cua cay" << node->g << endl;
		// generate states
		for (int op = 1; op <= MAX_OP; op++) {
			State new_state;
			if(call_operator(node->state, new_state, op)) {
				if(find_state(new_state, explored)) {
					continue;
				}
				Node* n = find_node(new_state, frontiers);
				if(n == NULL) {
					n = new Node();
					n->parent = node;
					n->state = new_state;
					n->h = heuristic(new_state, goal_state);
					print_state(new_state);
					n->g = node->g + 1;
					n->f = n->g + n->h;
					cout << "============" << n->g << "==" << n->f << endl;
					frontiers.insert(n); 
				} else { // neu nut con moi tim duoc thuoc duong bien
					// kiem tra gia tri f cua nut con nho hon cac nut da nam trong frontiers hay khong
					// neu nho hon thi cap nhat lai, neu lon hon thi khong can lam gi ca
					n->g = node->g + 1;
					n->f = n->g + n->h;
				}
			}
		}
	}
	
	return NULL;
}

void print_path(Node *r) {
	int i = 0;
	stack<State> q;
	cout << "\nDuong di loi giai\n";
	
	while (r->parent != NULL) {
		q.push(r->state);
		r = r->parent;
	}
	
	while (!q.empty()) {
		cout << "\nTrang thai thu" << i++ << endl;
		print_state(q.top());
		cout << endl;
		q.pop();
	}
}

State* read_file(string file) {
	ifstream fin(file);
	State *s = new State();
	for (int row = 0; row < BOARD_ROWS; row++) {
		for (int col = 0; col < BOARD_COLS; col++) {
			fin >> s->num[row][col];
		}
	}
	fin >> s->empty_row >> s->empty_col;
	return s;
}

int main() {
	State *goal_state;
	goal_state = read_file("goal.txt");
	print_state(*goal_state);
	
	State *s = read_file("01.txt");
	cout << "Trang thai ban dau" << endl;
	print_state(*s);
	
	vector<State> explored_h1; // gan trang thai dau tien cho close
	Node* n = BFS(*s, *goal_state, &explored_h1, h1);
	
	delete n;
	delete s;
	
	getchar();
	return 0;
}

