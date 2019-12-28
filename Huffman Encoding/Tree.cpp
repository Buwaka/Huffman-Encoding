#include "pch.h"
#include "Tree.h"
#include <string>

Tree::Tree(int w, char c)
{
	weight = w;
	character = c;
	left = right = nullptr;
}

Tree::Tree(int w, Tree* Left, Tree* Right)
{
	weight = w;
	character = '\0';
	left = Left;
	right = Right;
}

Tree::~Tree()
{
}

int Tree::getWeight() const
{
	return weight;
}

void Tree::printTree(string& bitString) const
{

	if (left != nullptr)
	{
		left->print(bitString, "0");
	}

	if (right != nullptr)
	{
		right->print(bitString, "1");
	}



}

void Tree::Compress(string& bitstring, string bits)
{

	if (character != '\0')
	{
		size_t pos;
		while ((pos = bitstring.find(character)) != std::string::npos)
		{
			bitstring.replace(pos, 1, bits, 0, bits.size());
		}
	}

	if (left != nullptr)
	{
		left->Compress(bitstring, bits + "0");
	}

	if (right != nullptr)
	{
		right->Compress(bitstring, bits + "1");
	}
}

void Tree::Decompress(string & bitstring)
{


	for (size_t i = 0; i < bitstring.size(); i++)
	{
		size_t start = i;
		const Tree *current = this;
		while (current->left != nullptr || current->right != nullptr)
		{
			if (bitstring[i] == '0')
				current = current->left;
			else
				current = current->right;

			i++;
		}

		bitstring.replace(start, i - start, &current->character);
		i = start;
	}
}

void Tree::print(string & out, string bits)
{

	if (character != '\0')
	{
		out += string(1,character) + ": " + bits + "\n";
	}

	if (left != nullptr)
	{
		left->print(out, bits + "0");
	}

	if (right != nullptr)
	{
		right->print(out, bits + "1");
	}
}
