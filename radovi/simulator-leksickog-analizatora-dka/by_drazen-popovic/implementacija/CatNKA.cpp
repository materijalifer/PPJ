#include "CatNKA.h"


CatNKA::CatNKA(void)
{
}

CatNKA::~CatNKA(void)
{
}

CatNKA::CatNKA(StateP nullState)
{
	nullState_ = nullState;
}

void CatNKA::make(NKA *m1, NKA *m2)
{
	//startState od m1 postaje startState od ovog NKA
	for(int i = 0; i < m1->startState.size(); i++)
		startState.push_back(m1->startState[i]);
	//e1 stanja su neprihvacena
	for(int i = 0; i < m1->endState.size(); i++)
		m1->endState[i]->acc = false;

	StateP e1State, s2State;
	//svim e1 stanjima prepisujemo prijelaze od s2 stanja
	for(int i = 0; i < m1->endState.size(); i++)
	{
		e1State = m1->endState[i];
		//stavljamo prijelaze od svih s2 stanja
		for(int j = 0; j < m2->startState.size(); j++)
		{
			s2State = m2->startState[j];
			//sve prijelaze
			e1State->setTransitions( s2State->transitions );
			//ako je s2State prihvatljiv, onda cijeli e1State mora biti isto
			if(s2State->acc == true) e1State->acc = true;
		}
	}
	
	//Naposljetku stavljamo u endState ovog NKA m2->endState
	for(int i = 0; i < m2->endState.size(); i++)
		endState.push_back( m2->endState[i]);

}
