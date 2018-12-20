#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;
// Each pair is of the form
// <Vertex, EdgeWeight>
//
// FO r unweighted graphs store 1 or drop the second attribute
// O(V + E) space complexity
// Ideal for enumarating lists of neighbors efficiently
//
// Alternatively, we could use an edge list based on edge weights
// vector<pair<int,ii> > EdgeList;

int main() {
	return 0;
}
