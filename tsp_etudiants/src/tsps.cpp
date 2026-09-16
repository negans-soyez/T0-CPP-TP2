#include <iostream>
#include <limits>
#include "tsps.h"


//----------------------------------------------------------------------------------------
//--- Private class methods --------------------------------------------------------------
//----------------------------------------------------------------------------------------

bool TravelingSalesmanProblemSolver::ExplorationIsOver( const int level )
{
	/* TODO : CODE A CORRIGER ET COMPLETER */
	return true;
}

bool TravelingSalesmanProblemSolver::IsPossible( const int choice, const int level )
{
	/* TODO : CODE A CORRIGER ET COMPLETER */
	return false;
}

void TravelingSalesmanProblemSolver::Include( const int choice, const int level )
{
	const Matrix & costs(m_Instance->GetCostMatrix());
	/* TODO : CODE A COMPLETER */
}

void TravelingSalesmanProblemSolver::Exclude( const int choice, const int level )
{
	const Matrix & costs(m_Instance->GetCostMatrix());
	/* TODO : CODE A COMPLETER */
}


//----------------------------------------------------------------------------------------
//--- Public class methods ---------------------------------------------------------------
//----------------------------------------------------------------------------------------

TravelingSalesmanProblemSolver::TravelingSalesmanProblemSolver( Instance *instance ) : m_Instance(instance)
{
	/* RIEN N'EST A MODIFIER ICI */
	int nb_nodes(m_Instance->GetNbNodes());


	m_Included.reserve(nb_nodes);
	m_Included.assign(nb_nodes, false);
	m_Cost     = 0.0;
	m_BestCost = std::numeric_limits<double>::infinity();
	m_NbNodes  = 0;
}

void TravelingSalesmanProblemSolver::Backtracking( const int k )
{
	const Matrix & costs(m_Instance->GetCostMatrix());
	int nb_nodes(m_Instance->GetNbNodes());
	double cost;


	// We increment the number of explored nodes
	m_NbNodes++;

	// If the exploration is complete, we evaluate the tour and update the best current solution
	if( ExplorationIsOver(k) )
	{
		/* CODE A COMPLETER */
		return;
	}

	// Otherwise, we try each available node and continue recursively
	for( int i=0; i<nb_nodes; i++ )
	{
		if( IsPossible(i,k) )
		{
			Include(i,k);
			Backtracking(k+1);
			Exclude(i,k);
		}
	}
}

std::uint64_t TravelingSalesmanProblemSolver::GetNbNodes() const
{
	/* RIEN N'EST A MODIFIER ICI */
	return m_NbNodes;
}
