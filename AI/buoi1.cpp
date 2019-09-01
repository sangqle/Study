#include <iostream>
#include <vector>
#include <stack>
using namespace std; 

//bieu dien mot trang thai
typedef struct State *Pstate;
typedef struct State{
	int x, y;
	Pstate parent; // con tro tra ve trang thai cha
	int hd; // hanh dong phat sinh
};

// phuong thuc kiem tra trang thai dich
bool goalcheck(Pstate s) {
	if((s->x == 6) || (s->y ==6)) return true;
	return false;
}

Pstate Cyx(Pstate s) {
	if((s->y > 0) && (s->x < 9)) {
		Pstate result = new State;
		result->x = min((s->x + s->y), 9);
		result->y = max(s->y + s->x - 9, 0);
		result->parent = s;
		return result;
	}
	return NULL;
}

Pstate Cxy(Pstate s) {
	if((s->x > 0) && (s->y < 4)) {
		Pstate result = new State;
		result->x = max(s->x + s->y - 4, 0);
		result->y = min((s->x + s->y), 4);
		result->parent = s;
		return result;
	}
	return NULL;
}

Pstate LamdayX(Pstate s) {
	if(s->x < 9) {
		Pstate result = new State;
		result->x = 9;
		result->y = s->y;
		result->parent = s;
		return result;
	}
	return NULL;
}
Pstate LamrongX(Pstate s) {
	if(s->x > 0) {
		Pstate result = new State;
		result->x = 0;
		result->y = s->y;
		result->parent = s;
		return result;
	}
	return NULL;
}

Pstate LamdayY(Pstate s) {
	if(s->y < 4) {
		Pstate result = new State;
		result->x = s->x;
		result->y = 4;
		result->parent = s;
		return result;
	}
	return NULL;
}
Pstate LamrongY(Pstate s) {
	if(s->y > 0) {
		Pstate result = new State;
		result->x = s->x;
		result->y = 0;
		result->parent = s;
		return result;
	}
	return NULL;
}

Pstate call_operator(Pstate s, int op_no) {
	switch(op_no) {
		case 1:
			return Cyx(s);
		case 2:
			return Cxy(s);
		case 3:
			return LamdayX(s);
		case 4:
			return LamdayY(s);
		case 5:
			return LamrongX(s);
		case 6:
			return LamrongY(s);
		default:
			return NULL;
	} 
}

bool foundstate(Pstate pstate, vector<Pstate> openlist) {
	for(Pstate tmp : openlist) {
		if(pstate->x == tmp->x && pstate->y == tmp->y) {
			return true;
		}
	}
	return false;
}

Pstate DFS() {
	Pstate pStart = new State;
	pStart->x = 0;
	pStart->y = 0;
	pStart->parent = NULL;
	
	stack<Pstate> Frontier;
	Frontier.push(pStart);
	vector<Pstate> explored;
	Pstate kiemtra;
	cout<<"Bat Dau \n";
	cout<<"0, 0 \n";
	while(!Frontier.empty()) {
		kiemtra = Frontier.top();
		Frontier.pop();
		if(goalcheck(kiemtra)) {
			return kiemtra;
		}
		explored.push_back(kiemtra);
		for(int op=1; op < 6; op++) {
			Pstate newstate = call_operator(kiemtra, op);
			if(newstate != NULL) {
				if(foundstate(newstate, explored)) {
					continue;
				}
				newstate->hd = op;
				Frontier.push(newstate);
			}
		}
	}
	return NULL;
}


int main() {
	// bieu dien trang thai ban dau
	Pstate p = DFS();
	while(p) {
		cout <<p->x<<" "<<p->y<<endl;
		p = p->parent;
	}
}
