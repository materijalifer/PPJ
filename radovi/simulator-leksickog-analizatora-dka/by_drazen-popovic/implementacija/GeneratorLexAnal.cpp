#include "GeneratorLexAnal.h"
#include "State.h"
#include <iostream>
#include "NKA.h"
#include "KleenNKA.h"
#include "CatNKA.h"
#include "charNKA.h"
#include "UnionNKA.h"

NKA* GeneratorLexAnal::genPart(StateP nullState, int* i, char* regex)
{
	vector<NKA*> nkas;

	//moramo izgraditi prvi charNKA
	charNKA *prviNka = new charNKA(nullState);
	prviNka->make(regex[*i]);
	nkas.push_back( prviNka );
	(*i)++;

	for(; *i < strlen(regex); (*i)++)
	{
		if( regex[*i] == '\\')
		{
			//escape: sljedeci znak jest alfabet, operand...ne operator!
			(*i)++;
			charNKA *nka = new charNKA(nullState);
			nka->make(regex[*i]);
			nkas.push_back( nka );
			continue;
		}
		
		else if( isAlphabet(regex[*i]))
		{
			if(isAlphabet(regex[*i+1]) || regex[*i + 1] == '\\')
			{
				//sad smo na 12&3& >a< b&c|
				//moramo pomaknuti natrag i---poslije je continue
				(*i)--;
				break;
			}
			charNKA *nka = new charNKA(nullState);
			nka->make(regex[*i]);
			nkas.push_back( nka );
		}
		else if( regex[*i] == '|')
		{
			UnionNKA* nka = new UnionNKA(nullState);
			int size = nkas.size();
			nka->make(nkas[size - 2] , nkas[size - 1]);
			nkas.pop_back();
			nkas.pop_back();
			nkas.push_back( nka );
			if(strchr("|&", regex[*i +1]) != NULL)	break;
			
		}
		else if( regex[*i] == '&')
		{
			CatNKA* nka = new CatNKA(nullState);
			int size = nkas.size();
			nka->make(nkas[size - 2] , nkas[size - 1]);
			nkas.pop_back();
			nkas.pop_back();
			nkas.push_back( nka );
			if( strchr("|&", regex[*i +1]) != NULL)	break;
		}
		else if( regex[*i] == '*' )
		{
			KleenNKA* nka = new KleenNKA(nullState);
			int size = nkas.size();
			nka->make(nkas[size - 1]);
			nkas.pop_back();
			nkas.push_back(nka);
			if(strchr("|&", regex[*i +1]) != NULL && nkas.size() == 1)	break;
		}
	}
	return nkas[0];
}

void GeneratorLexAnal::error(char* str)
{
	std::cout<< "error:"<<str<<std::endl;
	exit(-1);
}
GeneratorLexAnal::GeneratorLexAnal(void)
{
}

GeneratorLexAnal::~GeneratorLexAnal(void)
{
}

void GeneratorLexAnal::generate()
{
	vector<NKA*> nkas; //privremeni stog za NKAove
		
	//glavna petlja: generiramo NKAove za sve regularne izraze!!!
	for(int j = 0; j < regExps.size(); j++)
	{
	//stvaram null stanje!
	StateP nullState = new State();
	nullState->acc = false;
	nullState->isNullState = true;
	nullState->setReg(regExps[j]); 
	nullState->alphabet = alphabet;
	//samo na null stanje stavimo designation, 
	//sva stanja cije je ovo null stanje koriste taj designation
	//NAPOMENA: svaki reg izraz dobiva svoje nullState
	
	char* regex = regExps[j]->regex;
		
	//na kraju ovog algoritma ostaje na stogu nkas...NKA jedan jedini!
	for(int i = 0; i < strlen(regex); i++)
	{
		if( regex[i] == '\\')
		{
			//escape: sljedeci znak jest alfabet, operand...ne operator!
			i++;
			charNKA *nka = new charNKA(nullState);
			nka->make(regex[i]);
			nkas.push_back( nka );
			continue;
		}
		else if( isAlphabet(regex[i]))
		{
			if(isAlphabet(regex[i+1]) || regex[i + 1] == '\\')
			{
				//za regularne tipa ab&c&12&3&| -> abc | 123
				nkas.push_back(genPart(nullState, &i, regex));
				continue;
			}
			charNKA *nka = new charNKA(nullState);
			nka->make(regex[i]);
			nkas.push_back( nka );
		}
		else if( regex[i] == '|')
		{
			UnionNKA* nka = new UnionNKA(nullState);
			int size = nkas.size();
			nka->make(nkas[size - 2 ] , nkas[size - 1]);
			nkas.pop_back();
			nkas.pop_back();
			nkas.push_back( nka );
		}
		else if( regex[i] == '&')
		{
			int size = nkas.size();
			CatNKA* nka = new CatNKA(nullState);
			nka->make(nkas[size - 2 ] , nkas[size - 1]);
			nkas.pop_back();
			nkas.pop_back();
			nkas.push_back( nka );
		}
		else if( regex[i] == '*' )
		{
			KleenNKA* nka = new KleenNKA(nullState);
			int size = nkas.size();
			nka->make(nkas[size - 1]);
			nkas.pop_back();
			nkas.push_back(nka);
		}
	}
	//Kad zavrsimo normalno taj jedini ostali NKA na stogu stavimo u outputNKAS!
	outputNKAS.push_back( nkas[0] );

	//cistimo stog za sljedecu iteraciju/regularni izraz!
	nkas.clear();
	}

}

int GeneratorLexAnal::isAlphabet(char alpha)
{
	for(int i = 0; i < alphabet.size(); i++)
	{
		if( alphabet.at(i) == alpha ) return 1;
	}
	return 0;
}

