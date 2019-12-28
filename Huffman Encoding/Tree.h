#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Tree {
public:
	Tree(int w, char c);
	Tree(int w, Tree* Left, Tree* Right);
	~Tree();
	int getWeight() const;
	void printTree(string& bitString) const;
	void Compress(string& bitstring, string bits = "");
	void Decompress(string& bitstring);
private:
	void print(string& out, string bits);
	Tree* left;
	Tree* right;
	int weight;
	char character;
};

struct TreeWrapper {
	TreeWrapper() {
		tree = nullptr;
	}
	TreeWrapper(Tree* t) {
		tree = t;
	}
	bool operator<(const TreeWrapper &tw) const {
		return tree->getWeight() > tw.tree->getWeight();
	}
	Tree* tree;
};