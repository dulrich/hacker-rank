#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct EvenNode {
	int value;
	std::vector<int> *children;
};

int split_even(EvenNode *tree, int index, int *broken) {
	int count = 1;
	int l = tree[index].children->size();
	
	for(int i = 0; i < l; i++) {
		count += split_even(tree, tree[index].children->at(i), broken);
	}
	
	if (index > 0 && count % 2 == 0) {
		(*broken)++;
	}
	
	return count;
}

void insert_edge(EvenNode *tree, int parent_val, int index) {
	for(int i = 0; i < index; i++) {
		if (tree[i].value == parent_val) {
			tree[i].children->push_back(index);
			break;
		}
	}
}

int main() {
	int n, m;
	cin >> n;
	cin >> m;
	
	struct EvenNode tree[n];
	
	int child, parent;
	
	cin >> child >> parent;
	
	tree[0].value = parent;
	tree[0].children = new std::vector<int>();
	tree[0].children->push_back(1);
	
	tree[1].value = child;
	tree[1].children = new std::vector<int>();
	
	for(int i = 2; i <= m; i++) {
		cin >> child >> parent;
		
		
		tree[i].value = child;
		tree[i].children = new std::vector<int>();
		insert_edge(tree, parent, i);
	}
	
	int broken = 0;
	int res = split_even(tree, 0, &broken);
	
	if (res % 2 == 0) {
		printf("%d\n", broken);
	}
	else {
		printf("failure\n");
	}
	
	return 0;
}
