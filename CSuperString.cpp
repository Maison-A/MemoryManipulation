// --------------------------------------------------------------------------------
// Name: 
// Abstract: 
// --------------------------------------------------------------------------------
// -------------------------------------------------------------------------------- //
//										Includes
// -------------------------------------------------------------------------------- //
#include "CSuperString.h";
#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#pragma region "Constructors"
// -------------------------------------------------------------------------------- //
// Name: CSuperString
// Abstract: 
// -------------------------------------------------------------------------------- //
CSuperString::CSuperString()
{
	Initialize("");
}



// -------------------------------------------------------------------------------- //
// Name: Parameterized Constructor #1
// Abstract: const char*
// -------------------------------------------------------------------------------- //
CSuperString::CSuperString(const char* pstrStringToCopy)
{
	Initialize(pstrStringToCopy);
}



// -------------------------------------------------------------------------------- //
// Name: Parameterized Constructor #2
// Abstract: boolean
// -------------------------------------------------------------------------------- //
CSuperString::CSuperString(const bool blnBooleanToCopy)
{
	Initialize("");

	// funnel answer into assign operator
	if (blnBooleanToCopy == true)
	{
		*this = "true";
	}
	else
	{
		*this = "false";
	}
}



// -------------------------------------------------------------------------------- //
// Name: Parameterized Constructor #3
// Abstract: char
// -------------------------------------------------------------------------------- //
CSuperString::CSuperString(const char chrLetterToCopy)
{
	// create source "string", a null terminator and pass in
	char strSource[2] = { chrLetterToCopy, 0 };
	Initialize(strSource);
}



// -------------------------------------------------------------------------------- //
// Name: Parameterized Constructor #4
// Abstract: short
// -------------------------------------------------------------------------------- //
CSuperString::CSuperString(const short shtShortToCopy)
{
	// max value of short is 32767, +1 digit for sign, 1 for terminator and 1 for caution
	char strSource[8] = "";

	sprintf(strSource, "%hd", shtShortToCopy);
	Initialize(strSource);
}



// -------------------------------------------------------------------------------- //
// Name: Parameterized Constructor #5
// Abstract: int
// -------------------------------------------------------------------------------- //
CSuperString::CSuperString(const int intIntegerToCopy)
{
	char strSource[13] = "";
	
	sprintf(strSource, "%i", intIntegerToCopy);
	Initialize(strSource);

}



// -------------------------------------------------------------------------------- //
// Name: Parameterized Constructor #6
// Abstract: long
// -------------------------------------------------------------------------------- //
CSuperString::CSuperString(const long lngLongToCopy)
{
	char strSource[22] = "";

	sprintf(strSource, "%d", lngLongToCopy);
	Initialize(strSource);
}



// -------------------------------------------------------------------------------- //
// Name: Parameterized Constructor #7
// Abstract: float
// -------------------------------------------------------------------------------- //
CSuperString::CSuperString(const float sngFloatToCopy)
{
	// dynamic mem allocation to set size of char array

	int intArraySize = 0;
	//int intSizeOfArr = sizeof(float);
	intArraySize += 3;

// max value of float is 340282346638528859811704183484516925440.0000000 (46)
// +1 digit for sign, 1 for terminator and 1 for caution
	char strSource[50] = "";
	sprintf(strSource, "%f", sngFloatToCopy);
	Initialize(strSource);
	//palngValues = (long*)malloc(sizeof(long) * lngArraySize) * /


}


// -------------------------------------------------------------------------------- //
// Name: Parameterized Constructor #8
// Abstract: double
// -------------------------------------------------------------------------------- //
CSuperString::CSuperString(const double dblDoubleToCopy)
{
// max value of float is 1.79769e+308 (exponential form)
// +1 digit for sign, 1 for terminator and 1 for caution
	char strSource[15] = "";

	sprintf(strSource, "%g", dblDoubleToCopy);
	Initialize(strSource);
}



// -------------------------------------------------------------------------------- //
// Name: Parameterized Constructor #9
// Abstract: 
// -------------------------------------------------------------------------------- //
CSuperString::CSuperString(const CSuperString &ssStringToCopy)
{
	Initialize(ssStringToCopy.ToString());
}



// -------------------------------------------------------------------------------- //
// Name: Initialize
// Abstract: char*
// -------------------------------------------------------------------------------- //
void CSuperString::Initialize(const char* pstrSource)
{
	m_pstrSuperString = 0;

	// all memory allocation through the assignment operator
	*this = pstrSource;
}



// -------------------------------------------------------------------------------- //
// Name: ~CSuperString
// Abstract: destroy!
// -------------------------------------------------------------------------------- //
CSuperString::~CSuperString()
{
	CleanUp();
}



	// -------------------------------------------------------------------------------- //
	// Name: CleanUp
	// Abstract: destroy!
	// -------------------------------------------------------------------------------- //
	void CSuperString::CleanUp()
	{
		DeleteString(m_pstrSuperString);
	}
	


		// -------------------------------------------------------------------------------- //
		// Name: DeleteString
		// Abstract: destory!
		// -------------------------------------------------------------------------------- //
			void CSuperString::DeleteString(char* &pstrSource)
			{
				// check if anything is there
				if (pstrSource != 0)
				{
					// "sell the house and chuck the keys"
					delete pstrSource;
					pstrSource = 0;
				}
			}
#pragma endregion

#pragma region "operators"
// -------------------------------------------------------------------------------- //
// Name: operator = 
// Abstract: assignment operator
// -------------------------------------------------------------------------------- //
void CSuperString::operator = (const char chrLetterToCopy)
{
	char strSource[2] = { chrLetterToCopy, 0 };
	*this = strSource;
}



// -------------------------------------------------------------------------------- //
// Name: operator = 
// Abstract: assignment operator
// -------------------------------------------------------------------------------- //
void CSuperString::operator = (const char* pstrSource)
{
	// check if self assigned 
	if (m_pstrSuperString != pstrSource)
	{
		CleanUp();

		DeepCopy(pstrSource);
	}
}
#pragma endregion

#pragma region "String Manipulation"
// -------------------------------------------------------------------------------- //
// Name: ToUpperCase
// Abstract: return pointer to uppercase version of string
// -------------------------------------------------------------------------------- //
const char* CSuperString::ToUpperCase()
{
	char* pstrUpperCase = 0;

	// make copy of super string
	// every call to new must be paired with call to delete
	// the instantce that made the call to new should be the one to call delete
	pstrUpperCase = CloneString(m_pstrSuperString);

	// upper case it(get to use built in funcs!)
	strupr(pstrUpperCase);

	return pstrUpperCase;
}
#pragma endregion

#pragma region "To<DataType>"
// -------------------------------------------------------------------------------- //
// Name: ToString 
// Abstract: make value a string
// -------------------------------------------------------------------------------- //
const char* CSuperString::ToString() const
{
	return m_pstrSuperString;
}



// -------------------------------------------------------------------------------- //
// Name: ToBoolean 
// Abstract: return bool value from string
// -------------------------------------------------------------------------------- //
bool CSuperString::ToBoolean() 
{
	bool blnValue = false;

	if (strcmp(ToLowerCase(), "true") == 0)
	{
		blnValue = true;
	}
	
	else if (strcmp(ToLowerCase(), "1") == 0)
	{
		blnValue = true;
	}
	
	
	return blnValue;
}



// -------------------------------------------------------------------------------- //
// Name: ToShort 
// Abstract: create a short from string
// -------------------------------------------------------------------------------- //
short CSuperString::ToShort() 
{
	short shtValue = 0;

	shtValue = (short)atoi(m_pstrSuperString);
	return shtValue;

}



// -------------------------------------------------------------------------------- //
// Name: ToInteger 
// Abstract: create an integer from string
// -------------------------------------------------------------------------------- //
int CSuperString::ToInteger()
{
	int intValue = 0;

	intValue = (int)atoi(m_pstrSuperString);
	return intValue;

}




// -------------------------------------------------------------------------------- //
// Name: ToLong 
// Abstract: create an integer from string
// -------------------------------------------------------------------------------- //
long CSuperString::ToLong()
{
	long lngValue = 0;

	lngValue = (long)atol(m_pstrSuperString);
	return lngValue;

}




// -------------------------------------------------------------------------------- //
// Name: ToFloat 
// Abstract: create an integer from string
// -------------------------------------------------------------------------------- //
float CSuperString::ToFloat()
{
	float fltValue = 0;

	fltValue = (float)atof(m_pstrSuperString);
	return fltValue;

}




// -------------------------------------------------------------------------------- //
// Name: ToDouble 
// Abstract: create an integer from string
// -------------------------------------------------------------------------------- //
double CSuperString::ToDouble()
{
	double dblValue = 0;

	dblValue = atof(m_pstrSuperString);
	return dblValue;

}
#pragma endregion

#pragma region "Tools"
// -------------------------------------------------------------------------------- //
// Name: Length
// Abstract: determine length of string
// -------------------------------------------------------------------------------- //
long CSuperString::Length() const
{
	long lngLength = 0;
	lngLength = (long)strlen(m_pstrSuperString);

	return lngLength;
}



// -------------------------------------------------------------------------------- //
// Name: DeepCopy 
// Abstract: make a deep copy of the string
// -------------------------------------------------------------------------------- //
void CSuperString::DeepCopy (const char* pstrSource)
{
	m_pstrSuperString = CloneString(pstrSource);
}
	


	// -------------------------------------------------------------------------------- //
	// Name: CloneString
	// Abstract: assignment operator
	// -------------------------------------------------------------------------------- //
	char* CSuperString::CloneString(const char* pstrSource)
	{
		char* pstrClone = 0;
		long lngLength = 0;

		// check if null
		if (pstrSource != 0)
		{
			// if not null
			lngLength = strlen(pstrSource);
			pstrClone = new char[lngLength + 1];
			strcpy_s(pstrClone, lngLength + 1, pstrSource);
		}
		else
		{
			// if yes then default to empty string
			pstrClone = new char[1];
			*(pstrClone + 0) = 0;
		}
		return pstrClone;
	}






// -------------------------------------------------------------------------------- //
// Name: Print
// Abstract: print format
// -------------------------------------------------------------------------------- //
	void CSuperString::Print(const char* pstrCaption) const
	{
		cout << endl;
		cout << pstrCaption << endl;
		cout << "---------------------------" << endl;

		if (Length() > 0)
		{
			cout << m_pstrSuperString << endl;
		}
		else
		{
			cout << "- EMPTY STRING" << endl;
		}
		cout << endl;
	}
#pragma endregion