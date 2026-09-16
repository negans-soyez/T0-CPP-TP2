#include <iostream>
#include <cstdlib>
#include "tsps.h"
#include "instance.h"


/* Main entry point of the program. The program aims at solving the Symmetric Traveling Salesman Problem (STSP). The program 
 * loads an STSP instance, prints it, performs exhaustive search, prints the results and releases allocated resources. 
 * 
 * Typical usage example: ./main.exe data/instance3_100_10.txt
 * 
 * where instance number=3, nb nodes=10 and seed=100. */
int main( int argc, char **argv )
{
	TravelingSalesmanProblemSolver* tsps=NULL; // STSP solver
	Instance *instance=NULL;                   // STSP instance


	// We check if the instance filename is available from the command line
	if( argc != 2 )
	{
		std::cerr << "usage: " << argv[0] << " instance_filename\n";
		return EXIT_FAILURE;
	}

	// We load and print the instance
	instance = new Instance;

	if( !instance->Load(argv[1]) )
	{
		std::cerr << "error: unable to load instance\n";
		delete instance;
		return EXIT_FAILURE;
	}

	instance->Print();

	// We try to solve the instance
	tsps = new TravelingSalesmanProblemSolver(instance);
	tsps->Backtracking(0);
	std::cout << "number of explored nodes -> " << tsps->GetNbNodes() << std::endl; // CAUTION: DO NOT EDIT THIS LINE

	// We do memory deallocations
	delete tsps;
	delete instance;

	/*CreateInstance(100, 5, "data/instance1_100_5.txt"); CreateInstance(200, 5, "data/instance2_200_5.txt");
	CreateInstance(100, 10, "data/instance3_100_10.txt"); CreateInstance(200, 10, "data/instance4_200_10.txt");
	CreateInstance(100, 14, "data/instance5_100_14.txt"); CreateInstance(200, 14, "data/instance6_200_14.txt");*/

	return EXIT_SUCCESS;
}
