#pragma once

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
	std::unordered_map<char, size_t> characterTable;

	for (size_t i = 0; i < input.length(); i++)
	{
		characterTable[input[i]]++;
	}

	for (auto pair : characterTable)
	{
		que.push(new Tree(pair.second, pair.first));
	}

	while (que.size() > 1)
	{
		Tree* x(que.top().tree);
		que.pop();
		Tree* y(que.top().tree);
		que.pop();

		Tree* node = new Tree(x->getWeight() + y->getWeight(), x, y);

		que.push(node);
	}
}