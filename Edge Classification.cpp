#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#define Infinity 1000
using namespace std;
class Graph
{
private:
	class GraphNode
	{
	public:
		string data;
		vector<GraphNode*> next;
		vector<string> ed;
		char color;
		int dist;
		int ft;
		string pred;
		GraphNode(string d)
		{
			data = d;
			color = 'w';
			dist = Infinity;
			pred = "";
			ft = Infinity;
		}
	};
	vector<GraphNode> gr;
	GraphNode* searchPre(string s)
	{
		for (int i = 0; i < gr.size(); i++)
			if (gr[i].data == s)
				return &gr[i];
		throw 0;
	}
	void visitDFS(GraphNode &g, int &ti)
	{
		ti++;
		g.dist = ti;
		g.color = 'g';
		vector<GraphNode *> &n = g.next;
		for (int k = 0; k != n.size(); k++)
		{
			if (n[k]->color == 'w')
			{
				n[k]->color = 'g';
				n[k]->pred = g.data;
				visitDFS(*n[k], ti);
				g.ed.push_back("Tree Edge");
			}
			else if (n[k]->color == 'g')
			{
				g.ed.push_back("Back Edge");
			}
			else if (n[k]->color == 'b')
			{
				if (g.dist < n[k]->dist)
					g.ed.push_back("Front Edge");
				else if (g.dist > n[k]->dist)
					g.ed.push_back("Cross Edge");
			}
			cout << g.data << " " << n[k]->data << " " << g.ed[k] << endl;
		}
		g.color = 'b';
		ti++;
		g.ft = ti;
	};
public:
	void insert(string d)
	{
		GraphNode tmp(d);
		gr.push_back(tmp);
	}
	void link(string a, string b)
	{
		for (vector<GraphNode>::iterator it = gr.begin(); it != gr.end(); it++)
			if (it->data == a)
			{
				it->next.push_back(searchPre(b));
				return;
			}
		throw 0;
	}
	int size() const
	{
		return gr.size();
	}
	void showDFS()
	{
		int ti = 0;
		for (vector<GraphNode>::iterator it = gr.begin(); it != gr.end(); it++)
		{
			it->color = 'w';
			it->dist = Infinity;
			it->pred = "";
		}
		for (vector<GraphNode>::iterator it = gr.begin(); it != gr.end(); it++)
		{
			if (it->color == 'w')
				visitDFS(*it, ti);
		}
	}
};
int main()
{
	Graph g;
	g.insert("1");
	g.insert("2");
	g.insert("3");
	g.insert("4");
	g.insert("5");
	g.insert("6");
	g.insert("7");
	g.insert("8");
	g.insert("9");
	g.insert("10");
	g.insert("11");
	g.insert("12");
	g.link("1", "2");
	g.link("1", "3");
	g.link("2", "4");
	g.link("2", "5");
	g.link("3", "6");
	g.link("3", "7");
	g.link("3", "12");
	g.link("5", "1");
	g.link("5", "8");
	g.link("5", "9");
	g.link("5", "10");
	g.link("7", "11");
	g.link("7", "12");
	g.link("7", "12");
	g.link("11", "8");
	g.showDFS();
	system("pause");
}