#ifndef TSP_H
#define TSP_H

#include <vector>
#include <cstdint>
#include "instance.h"


/* This class solves the Symmetric Traveling Salesman Problem (STSP) on a complete undirected loopless graph G=(V,E) 
   with N=|V| nodes. The STSP consists of finding a minimum-cost Hamiltonian cycle in G. The problem is NP-hard. The 
   backtracking algorithm implemented by this class performs an exhaustive search (optimal solution). */
class TravelingSalesmanProblemSolver
{
     private :
	Instance *m_Instance;         // STSP instance
	std::vector<int> m_Path;      // Current partially constructed path P
	std::vector<bool> m_Included; // Boolean array of size N where m_Included[i] indicates whether node i belongs to P
	double m_Cost;                // Cost of the partially constructed path P
	std::vector<int> m_BestPath;  // Best tour found P^*
	double m_BestCost;            // Cost of the best tour found P^*
	std::uint64_t m_NbNodes;      // Number of explored nodes in the search tree (CAUTION: handles STSP instances up to |V|=20)

	bool ExplorationIsOver( const int level );            // Exploration ends when all nodes have been visited
	bool IsPossible( const int choice, const int level ); // Checks if the node whose index is `choice' is available
	void Include( const int choice, const int level );    // Adds the node whose index is `choice' to the partial path P
	void Exclude( const int choice, const int level );    // Removes the node whose index is `choice' from the partial path P

     public :
	TravelingSalesmanProblemSolver( Instance *instance ); // Constructor
	void Backtracking( const int k );                     // Does exhaustive search from level k using backtracking
	std::uint64_t GetNbNodes() const;                     // Returns the number of explored nodes
};

#endif //TSP_H
