#include <limits>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <random>
#include <iomanip>
#include <cassert>
#include "instance.h"

//COUCOUUUUUUUUUUUUUUUUUUU


//----------------------------------------------------------------------------------------
//--- Public class methods ---------------------------------------------------------------
//----------------------------------------------------------------------------------------

Instance::Instance( const int seed, const int nb_nodes, const Matrix & costs ) : m_Seed(seed), m_NbNodes(nb_nodes), m_Costs(costs){}


//1) 
int Instance::GetSeed() const
{
	return m_Seed;
}

int Instance::GetNbNodes() const
{
	return m_NbNodes;
}

const Matrix & Instance::GetCostMatrix() const
{
	return m_Costs;
}


void Instance::Print() const
{

	std::cout << "seed -> " << m_Seed << std::endl;
	std::cout << "number of nodes -> " << m_NbNodes << std::endl;

	for (int i; i < m_NbNodes; i++){
		for (int j; j < m_NbNodes; j++){
			std::cout << m_Costs[i][j] << " " << std::endl;
		}
		std::cout << "\n" << std::endl;
	}



	/* TODO : A COMPLETER */
	/* ... */
}

bool Instance::Load( const char *filename )
{
	std::ifstream fp(filename);


	if( !fp )
		return false;

	if( !(fp>>m_Seed) || m_Seed<0 )
	{
		std::cerr << "error: invalid seed value" << std::endl;
		return false;
	}

	if( !(fp>>m_NbNodes) || m_NbNodes<=1 )
	{
		std::cerr << "error: invalid number of nodes" << std::endl;
		return false;
	}

	m_Costs = Matrix(m_NbNodes, Array(m_NbNodes));

	for( int i=0; i<m_NbNodes; i++ )
	{
		for( int j=0; j<m_NbNodes; j++ )
		{
			if( !(fp>>m_Costs[i][j]) )
			{
				std::cerr << "error: invalid cost matrix" << std::endl;
				return false;
			}
		}
	}

	if( !IsSymmetric() )
	{
		std::cerr << "error: the cost matrix is not symmetric" << std::endl;
		return false;
	}

	return true;
}

bool Instance::Save( const char* filename ) const
{
	std::ofstream fp(filename);


	if( !fp )
		return false;

	fp << std::setprecision(std::numeric_limits<double>::max_digits10);

	/* TODO : A COMPLETER */
	/* ... */

	return true;
}


//@negans-soyez
bool Instance::IsSymmetric() const
{
	double epsilon(std::numeric_limits<double>::epsilon());

	for ( int i=0; i<m_NbNodes; i++ )
	{
		for( int j=i+1; j<m_NbNodes; j++ )
		{
			// Différence absolue entre les coûts de l'arête (i,j) et (j,i)
			if( std::fabs(m_Costs[i][j]-m_Costs[j][i])>epsilon )
				return false;
		}
	}

	return true;
}


//-----------------------------------------------------------------------------------------
//--- Utility functions -------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

void CreateInstance( const int seed, const int nb_nodes, const char *filename )
{
	std::mt19937 generator(static_cast<std::mt19937::result_type>(seed));
	Matrix costs(nb_nodes, Array(nb_nodes));
	Instance *instance=NULL;


	assert(seed>0 && nb_nodes>1 && filename!=NULL);

	for( int i=0; i<nb_nodes; i++ )
	{
		for( int j=i+1; j<nb_nodes; j++ )
		{
			costs[i][j] = double(generator())/generator.max();
			costs[j][i] = costs[i][j];
		}
	}

	instance = new Instance(seed, nb_nodes, costs);
	instance->Save(filename);

	delete instance;
}
