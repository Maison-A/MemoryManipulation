// --------------------------------------------------------------------------------
//								Pre-compiler Directives
// --------------------------------------------------------------------------------
#pragma once		
#define _CRT_SECURE_NO_WARNINGS
// -------------------------------------------------------------------------------- //
//										Includes
// -------------------------------------------------------------------------------- //
#include <stdlib.h>
#include <iostream>
#include "CSuperString.h"
using namespace std;


// --------------------------------------------------------------------------- //
//									CONSTANTS
// --------------------------------------------------------------------------- //



// --------------------------------------------------------------------------- //
//								USER DEFINED TYPES
// --------------------------------------------------------------------------- //



// --------------------------------------------------------------------------- //
//									PROTOTYPES
// --------------------------------------------------------------------------- //
void ConstructorTests();


// --------------------------------------------------------------------------- //
//									MAIN
// --------------------------------------------------------------------------- //

void main()
{
	ConstructorTests();
	




	// cout << "I made it this far";
}



// -------------------------------------------------------------------------------- //
// Name: ConstructorTests
// Abstract: 
// -------------------------------------------------------------------------------- //
void ConstructorTests()
{
	CSuperString ssSource1;
	CSuperString ssSource2("I Love Star Wars");
	CSuperString ssSource3a(true);
	CSuperString ssSource3b(false);
	CSuperString ssSource4('A');
	CSuperString ssSource5a((short)SHRT_MIN);
	CSuperString ssSource5b((short)SHRT_MAX);
	CSuperString ssSource6b((int)INT_MIN);
	CSuperString ssSource6a((int)INT_MAX);
	CSuperString ssSource7a((long)LONG_MIN);
	CSuperString ssSource7b((long)LONG_MAX);
	CSuperString ssSource8a((float)FLT_MAX);
	CSuperString ssSource8b((float)FLT_MIN);
	CSuperString ssSource9a((double)DBL_MIN);
	CSuperString ssSource9b((double)DBL_MAX);
	CSuperString ssSource10(ssSource2);


	// --------------------------------------------------------------------------- //
	//								CONSTRUCTORS
	// --------------------------------------------------------------------------- //
	cout << "CONSTRUCTORS\n" << endl;
	cout << "--------------------------------------" << endl;
	cout << "1:  Default				->			" << ssSource1.ToString() << endl;
	cout << "2:  char*				->			" << ssSource2.ToString() << endl;
	cout << "3a: bool	(true)			->			" << ssSource3a.ToString() << endl;
	cout << "3b: bool	(false)			->			" << ssSource3b.ToString() << endl;
	cout << "4:  char				->			" << ssSource4.ToString() << endl;
	cout << "5a:  short	(MIN)			->			" << ssSource5a.ToString() << endl;
	cout << "5b:  short	(MAX)			->			" << ssSource5b.ToString() << endl;
	cout << "6a:  int	(MIN)			->			" << ssSource6a.ToString() << endl;
	cout << "6b:  int	(MAX)			->			" << ssSource6b.ToString() << endl;
	cout << "7a:  long	(MIN)			->			" << ssSource7a.ToString() << endl;
	cout << "7b:  long	(MAX)			->			" << ssSource7b.ToString() << endl;
	cout << "8a:  float	(MIN)			->			" << ssSource8a.ToString() << endl;
	cout << "8b:  float	(MAX)			->			" << ssSource8b.ToString() << endl;
	cout << "9a:  double (MIN)			->			" << ssSource9a.ToString() << endl;
	cout << "9b:  double (MAX)			->			" << ssSource9b.ToString() << endl;
	cout << "10: SuperString				->			" << ssSource10.ToString() << endl;
}



// -------------------------------------------------------------------------------- //
// Name: ToDataTypeTests
// Abstract: 
// -------------------------------------------------------------------------------- //
void ToDataTypeTests()
{
	CSuperString ssSource1a(true);
	CSuperString ssSource1b(false);
	CSuperString ssSource2a((short)SHRT_MIN);
	CSuperString ssSource2b((short)SHRT_MAX);
	CSuperString ssSource3a((int)INT_MIN);
	CSuperString ssSource3b((int)INT_MAX);
	CSuperString ssSource4a((long)LONG_MIN);
	CSuperString ssSource4b((long)LONG_MAX);
	CSuperString ssSource5a((float)FLT_MIN);
	CSuperString ssSource5b((float)FLT_MAX);
	CSuperString ssSource6a((double)DBL_MIN);
	CSuperString ssSource6b((double)DBL_MAX);



	// --------------------------------------------------------------------------- //
	//								TO<DATATYPE>
	// --------------------------------------------------------------------------- //
	cout << "CONSTRUCTORS\n" << endl;
	cout << "--------------------------------------"	<< endl;
	cout << "1a: bool	(false)			->			"	<< ssSource1a.ToBoolean() << endl;
	cout << "1b: bool	(true)			->			"		<< ssSource1b.ToBoolean() << endl;
	cout << "3a: short	(MIN)			->			"	<< ssSource2a.ToShort() << endl;
	cout << "3b: short	(MAX)			->			"	<< ssSource2b.ToShort() << endl;
	cout << "4a: int	(MIN)			->			"		<< ssSource3a.ToInteger() << endl;
	cout << "4b: int	(MAX)			->			"	<< ssSource3b.ToInteger() << endl;
	cout << "5a: long	(MIN)			->			"	<< ssSource4a.ToLong() << endl;
	cout << "5b: long	(MAX)			->			"	<< ssSource4b.ToLong() << endl;
	cout << "6a: float	(MIN)			->			"	<< ssSource5a.ToFloat() << endl;
	cout << "6b: float	(MAX)			->			"	<< ssSource5b.ToFloat() << endl;





}