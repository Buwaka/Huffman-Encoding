// Huffman Encoding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Tree.h"



void CreateTree(std::priority_queue<TreeWrapper>& que, string input)
{
	std::map<char, size_t> characterTable;

	for (size_t i = 0; i < input.length(); i++)
	{
		characterTable[input[i]]++;
	}

	std::vector<std::pair<char, size_t>> intermediate(characterTable.begin(),characterTable.end());

	std::sort(intermediate.begin(), intermediate.end(), [](std::pair<char, size_t> a, std::pair<char, size_t> b) {return a.second > b.second; });


	size_t length = intermediate.size();	

	for (size_t i = 0; i < length; i++)
	{
		que.push(TreeWrapper(new Tree(intermediate[i].second, intermediate[i].first)));
	}

	while (que.size() != 1)
	{
		Tree* x(que.top().tree);
		que.pop();
		Tree* y(que.top().tree);
		que.pop();

		Tree* node = new Tree(x->getWeight() + y->getWeight(),x,y);

		que.push(node);
	}

}


int main()
{
	std::string input;
	std::cout << "Input: ";
	std::getline(std::cin, input);

	std::priority_queue<TreeWrapper> que;

	CreateTree(que, input);

	string comp = input;
	que.top().tree->Compress(comp);

	std::cout << comp <<std::endl;

	std::string vstr{};
	que.top().tree->printTree(vstr);

	string decomp = comp;
	que.top().tree->Decompress(decomp);

    std::cout << decomp << std::endl;
	std::cout << vstr << std::endl;
}

