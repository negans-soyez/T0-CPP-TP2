#ifndef INSTANCE_H
#define INSTANCE_H

#include <vector>


// Aliases for convenience
typedef std::vector<double> Array;
typedef std::vector<Array> Matrix;

// Class describing an instance of the Symmetric Traveling Salesman Problem (STSP)
class Instance
{
     private:
	int m_Seed;     // Seed of the PRNG
	int m_NbNodes;  // Number of nodes
	Matrix m_Costs; // Cost matrix

     public:
	Instance( const int seed=0, 
	          const int nb_nodes=0, 
	          const Matrix & costs=Matrix() ); // Constructor
	int GetSeed() const;                       // Returns the seed of the PRNG
	int GetNbNodes() const;                    // Returns the number of nodes
	const Matrix & GetCostMatrix() const;      // Returns the cost matrix
	void Print() const;                        // Prints an instance
	bool Load( const char *filename );         // Loads an instance
	bool Save( const char* filename ) const;   // Saves an instance
	bool IsSymmetric() const;                  // Checks symmetry of cost matrix
};

// Utility function creating a new instance with cost matrix filled uniformly at random
void CreateInstance( const int seed, const int nb_nodes, const char *filename );

#endif //INSTANCE_H
