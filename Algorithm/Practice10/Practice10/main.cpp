// 2016112158 김희수
#include <iostream>
#include <vector>
#include <string>
#include "graph.h"
#include "DNA.h"
#include "Hamilton.h"
#include <map>
#include <list>
#include <algorithm>
using namespace std;


// 1. 먼저 주어진 spectrum을 그래프로 만든다. 이때 그래프는 방향그래프이며 표현은 인접행렬이다.
// 2. 주어진 그래프를 토대로 해밀턴 경로를 찾는다. 

string concat(string zero, list<string> queue)
{
	string result;
	if (zero == "")
	{
		result = "" + queue.front();
		queue.pop_front();
		result += queue.front().substr(2, 1);

		return result;
	}
	else
	{
		queue.pop_front();
		result = zero + queue.front().substr(2, 1);
		return result;
	}


}

class Node
{
public:
	string DNA;
	int number;
	vector<Node> childs;

	Node(string DNA, int number)
	{
		this->DNA = DNA;
		this->number = number;
		
	}

	void has_child(Node dest)
	{
		
		if (DNA[DNA.length() - 2] == dest.DNA[0] && DNA[DNA.length() - 1] == dest.DNA[1] && DNA !=dest.DNA)
		{
			childs.push_back(dest);
		}
	}

	string concat()
	{
		string result = DNA;

		list<Node> temp_childs;
		for (auto& child : childs)
			temp_childs.push_back(child);

		if (!temp_childs.empty())
		{
			result += temp_childs.front().DNA.substr(2, 1);
			temp_childs.pop_front();
		}

		return result;
	}

	
};

void connect(vector<Node>& nodes)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		for (int j = 0; j < nodes.size(); j++)
		{
			nodes[i].has_child(nodes[j]);
		}
	}
}

bool not_in(list<int> node, )

list<int> find_path(map<int, list<int>> graph, int start, int end, list<int> path)
{
	list<int> nothing;
	list<int> merged;
	merged.insert(merged.end(), path.begin(), path.end());
	merged.insert(merged.end(), start);
	if (start == end)
		return merged;

	
	if (graph.find(start) == m.end())
		return nothing;

	list<int> paths;
	for (auto& node : graph.find(start)->second)
	{
		if 
	}
}

int main()
{
	vector<Node> nodes = { Node("ATG",0), Node("TGG",1), Node("TGC",2), Node("GTG",3), Node("GGC",4), Node("GCA",5), Node("GCG",6), Node("CGT",7) };
	

	
	map<int, list<int>> connection = { {1,{4,5}}, {2,{5}}, {3,{4}}, {4,{1,3,5}}, {5,{1,2,4}} };




	

}