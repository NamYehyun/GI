#ifndef __BACKTRACK_H__
#define __BACKTRACK_H__

#include <iostream>
#include "graph.h"
#include "refine.h"
#include "cs.h"
#include "heap.h"
#include "memory.h"

using namespace std;

class Backtrack
{
	DAG* dag = NULL;
	CS* cs = NULL;
	long long* mapping = NULL;

	//variables used in backtracking (Workspace)
	// - for adaptive matching order
	vector<long long>* extCand = NULL;
	long long* weight = NULL;
	long long* numMappedParent = NULL;
	long long* candPos = NULL;
	long long* matchingOrder = NULL;
	char* isBinary = NULL;
	Heap* heap = NULL;
	// - for the partial failing set
	vector<long long>* failingset = NULL;
	

	void init();
	void clearWorkspace();

	DAG* buildDAG(Graph*, Coloring*);
	long long selectRoot(Graph*, Coloring*);

	CS* buildCS(DAG*, Graph*, Coloring*);
	long long binarySearch(long long*, long long, long long);

	void mapBinaryCell(Coloring*, long long*);

	bool backtrack(CS*, DAG*, long long*);
	//for the adaptive matching order
	void insertExtVertex(long long, long long);
	long long computeWeight(long long);
	void computeExtCand(long long);
	long long getMinExtVertex();
	void deleteExtVertex(long long);
	//for the partial failing set
	long long binarySearch(vector<long long>&, long long);
	void merge(vector<long long>&, vector<long long>&);
	void merge(vector<long long>&, long long*, long long);
	
public:
	Backtrack();
	~Backtrack();

	bool run(Coloring*, Graph*, Graph*);
};

#endif