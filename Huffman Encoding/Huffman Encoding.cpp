// Huffman Encoding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Tree.h"






int main()
{
	std::string input;
	std::cout << "Input: ";
	std::getline(std::cin, input);

	std::priority_queue<TreeWrapper> que;

	CreateHuffmanTree(que, input);

	string comp = input;
	que.top().tree->Compress(comp);

	std::cout << comp <<std::endl;

	std::string vstr{};
	que.top().tree->printTree(vstr);

	string decomp = comp;
	que.top().tree->Decompress(decomp);

    std::cout << decomp << std::endl;
	std::cout << vstr << std::endl;

	auto temp = que.top();
	que.pop();
	temp.Release();
}

