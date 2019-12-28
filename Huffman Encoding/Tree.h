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

	void Release();

private:
	void print(string& out, string bits);
	Tree* left;
	Tree* right;
	int weight;
	char character;
};

struct TreeWrapper {
	TreeWrapper() 
	{
		tree = nullptr;
	}

	TreeWrapper(Tree* t) 
	{
		tree = t;
	}

	void Release() 
	{
		if (tree)
		{
			tree->Release();
			delete tree;
		}
	}

	bool operator<(const TreeWrapper &tw) const 
	{
		return tree->getWeight() > tw.tree->getWeight();
	}

	Tree* tree;
};



static void CreateHuffmanTree(std::priority_queue<TreeWrapper>& que, string input)
{
	std::map<char, size_t> characterTable;

	for (size_t i = 0; i < input.length(); i++)
	{
		characterTable[input[i]]++;
	}

	std::vector<std::pair<char, size_t>> intermediate(characterTable.begin(), characterTable.end());

	std::sort(intermediate.begin(), intermediate.end(), [](std::pair<char, size_t> a, std::pair<char, size_t> b) {return a.second > b.second; });


	size_t length = intermediate.size();

	for (size_t i = 0; i < length; i++)
	{
		que.push(new Tree(intermediate[i].second, intermediate[i].first));
	}

	while (que.size() != 1)
	{
		Tree* x(que.top().tree);
		que.pop();
		Tree* y(que.top().tree);
		que.pop();

		Tree* node = new Tree(x->getWeight() + y->getWeight(), x, y);

		que.push(node);
	}
}