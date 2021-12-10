// -------------------------------------------------------------------------------- \\
// Name: CSuperString
// Abstract: final exam super string class
// -------------------------------------------------------------------------------- \\

// -------------------------------------------------------------------------------- //
//										DIRECTIVES
// -------------------------------------------------------------------------------- //
#include "CSuperString.h";
#include <iostream>
#include <algorithm>
#include <string.h>
//#include <bits/stdc++.h>
#include "CQueue.h"

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
	
	// set class level pointers to 0 and be sure to clean up in destructor
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

#pragma region "Operators"
// -------------------------------------------------------------------------------- //
// Name: operator = 
// Abstract: assignment operator
// -------------------------------------------------------------------------------- //
CSuperString& CSuperString::operator = (const char chrLetterToCopy)
{
	char strSource[2] = { chrLetterToCopy, 0 };
	*this = strSource;
	return *this;
}



// -------------------------------------------------------------------------------- //
// Name: operator = 
// Abstract: assignment operator
// -------------------------------------------------------------------------------- //
CSuperString &CSuperString::operator = (const char* pstrSource)
{

	DeepCopy(pstrSource);
	
	return *this;
}



// -------------------------------------------------------------------------------- //
// Name: operator = 
// Abstract: assignment operator
// -------------------------------------------------------------------------------- //
CSuperString& CSuperString::operator = (const CSuperString &ssStringToCopy)
{

	DeepCopy(ssStringToCopy.m_pstrSuperString);

	return *this;
}



// -------------------------------------------------------------------------------- //
// Name: operator += 
// Abstract: Concatenate operator - take string to append and copy it to a rezied original
// -------------------------------------------------------------------------------- //
void CSuperString::operator += (const char* pstrStringToAppend)
{
	char* pstrAppendedString = 0;
	long lngIndex = 0;
	long lngLengthOfOriginal = 0;
	long lngLengthToAppend = 0;
	long lngLengthOfBoth = 0;
	//char* CopyOfStringToAppend = 0;
	CSuperString CopyOfStringToAppend;
	CopyOfStringToAppend = CloneString(pstrStringToAppend);

	lngLengthToAppend = CopyOfStringToAppend.Length();
	lngLengthOfOriginal = this->Length();
	lngLengthOfBoth = lngLengthOfOriginal + lngLengthToAppend;
	
	// make a new char*
	pstrAppendedString = new char[lngLengthOfBoth + 1];

	// copy first half from old to new
	for (lngIndex = 0; lngIndex < lngLengthOfOriginal; lngIndex += 1)
	{
		*(pstrAppendedString + lngIndex) = *(m_pstrSuperString + lngIndex);

	}

	// copy second half
	for (lngIndex = lngIndex; lngIndex < lngLengthOfBoth; lngIndex += 1)
	{
		*(pstrAppendedString + lngIndex + 1) = *(CopyOfStringToAppend.m_pstrSuperString + lngIndex);
	}
	// delete old pointer and reset
	DeepCopy(pstrAppendedString);
	
}



// -------------------------------------------------------------------------------- //
// Name: operator += 
// Abstract: Concatenate operator
// -------------------------------------------------------------------------------- //
void CSuperString::operator += (const char chrCharacterToAppend)
{
	char* pstrAppendedString = 0;
	long lngIndex = 0;
	long lngLengthOfOriginal = 0;
	long lngLengthToAppend = 0;
	long lngLengthOfBoth = 0;

	lngLengthOfOriginal = this->Length();
	lngLengthOfBoth = lngLengthOfOriginal + 1;

	// make a new char*
	pstrAppendedString = new char[lngLengthOfBoth + 1];

	// copy first half from old to new
	for (lngIndex = 0; lngIndex < lngLengthOfOriginal; lngIndex += 1)
	{
		*(pstrAppendedString + lngIndex) = *(m_pstrSuperString + lngIndex);

	}

	// copy second half
	for (lngIndex = lngIndex; lngIndex < lngLengthOfBoth; lngIndex += 1)
	{
		*(pstrAppendedString + lngIndex + 1) = chrCharacterToAppend;
	}

	DeepCopy(pstrAppendedString);
	CleanUp();
	*m_pstrSuperString = *pstrAppendedString;
	
	// delete old pointer and reset
	//delete[]pstrAppendedString;
	//pstrAppendedString = 0;
}



// -------------------------------------------------------------------------------- //
// Name: operator += 
// Abstract: Concatenate operator
// -------------------------------------------------------------------------------- //
void CSuperString::operator += (const CSuperString& ssStringToAppend)
{
	char* pstrAppendedString = 0;
	long lngIndex = 0;
	long lngLengthOfOriginal = 0;
	long lngLengthToAppend = 0;
	long lngLengthOfBoth = 0;

	// CSuperString CopyOfStringToAppend;
	// CopyOfStringToAppend = CloneString(ssStringToAppend);

	lngLengthToAppend = ssStringToAppend.Length();
	lngLengthOfOriginal = this->Length();
	lngLengthOfBoth = lngLengthOfOriginal + lngLengthToAppend;

	// make a new char*
	pstrAppendedString = new char[lngLengthOfBoth + 1];

	// copy first half from old to new
	for (lngIndex = 0; lngIndex < lngLengthOfOriginal; lngIndex += 1)
	{
		*(pstrAppendedString + lngIndex) = *(m_pstrSuperString + lngIndex);

	}

	// copy second half
	for (lngIndex = lngIndex; lngIndex < lngLengthOfBoth; lngIndex += 1)
	{
		*(pstrAppendedString + lngIndex + 1) = *(ssStringToAppend.m_pstrSuperString + lngIndex);
	}
	
	DeepCopy(pstrAppendedString);
	//CleanUp();

	//*m_pstrSuperString = *pstrAppendedString;
	// delete old pointer and reset
	delete[]pstrAppendedString;
	pstrAppendedString = 0;

}



#pragma endregion

#pragma region "Index Finding"
// -------------------------------------------------------------------------------- //
// Name: FindFirstIndexOf
// Abstract: 
// -------------------------------------------------------------------------------- //
long CSuperString::FindFirstIndexOf(const char chrLetterToFind)
{
	long lngIndexOf = 0;
	long lngLength = Length();

	for (int intIndex = 0; intIndex <= lngLength; intIndex++)
	{
		if (*(m_pstrSuperString + intIndex) == chrLetterToFind)
		{
			lngIndexOf = intIndex;
			break;
		}
	}

	return lngIndexOf;
}



// -------------------------------------------------------------------------------- //
// Name: FindFirstIndexOf
// Abstract: 
// -------------------------------------------------------------------------------- //
long CSuperString::FindFirstIndexOf(const char chrLetterToFind, long lngStartIndex)
{
	long lngIndexOf = 0;
	long lngLength = Length();
	
	for (int intIndex = lngStartIndex; intIndex <= lngLength; intIndex++)
	{
		if (*(m_pstrSuperString + intIndex) == chrLetterToFind)
		{
			lngIndexOf = intIndex;
			break;
		}
	}

	return lngIndexOf;
}



// -------------------------------------------------------------------------------- //
// Name: FindLastIndexOf
// Abstract: 
// -------------------------------------------------------------------------------- //
long CSuperString::FindLastIndexOf(const char chrLetterToFind)
{
	long lngIndexOf = 0;
	long lngLength = Length();

	for (int intIndex = lngLength; intIndex >= 0; intIndex--)
	{
		if (m_pstrSuperString[intIndex] == chrLetterToFind)
		{
			lngIndexOf = intIndex;
		}
	}

	return lngIndexOf;
}



// -------------------------------------------------------------------------------- //
// Name: 
// Abstract: 
// -------------------------------------------------------------------------------- //
long CSuperString::FindFirstIndexOf(const char* pstrSubStringToFind)
{
	long lngIndexOf = 0;
	long lngLength = Length();
	char* pstrCompareMe = 0;
	//CSuperString pstrCompareMe;

	for (int intIndex = 0; intIndex <= lngLength; intIndex++)
	{
		*pstrCompareMe = *(m_pstrSuperString + intIndex);
		*(m_pstrSuperString + intIndex) += *(m_pstrSuperString + intIndex + 1);
		
		if (pstrCompareMe == pstrSubStringToFind)
		{
			lngIndexOf = intIndex;
		}
	}

	return lngIndexOf;
}



// -------------------------------------------------------------------------------- //
// Name: 
// Abstract: 
// -------------------------------------------------------------------------------- //
long CSuperString::FindFirstIndexOf(const char* pstrSubStringToFind, long lngStartIndex)
{
	return 0;
}



// -------------------------------------------------------------------------------- //
// Name: 
// Abstract: 
// -------------------------------------------------------------------------------- //
long CSuperString::FindLastIndexOf(const char* pstrSubStringToFind)
{
	return 0;
}
#pragma endregion

#pragma region "String Manipulation"
// -------------------------------------------------------------------------------- //
// Name: ToUpperCase
// Abstract: return pointer to uppercase version of string
// -------------------------------------------------------------------------------- //
CSuperString CSuperString::ToUpperCase()
{

	CSuperString ssToUpperCase;

	ssToUpperCase = m_pstrSuperString;
	
	// upper case it (we get to use built in funcs!)
	strupr(ssToUpperCase.m_pstrSuperString);

	return ssToUpperCase;
}



// -------------------------------------------------------------------------------- //
// Name: ToLowerCase
// Abstract: return pointer to lowercase version of string
// -------------------------------------------------------------------------------- //
CSuperString CSuperString::ToLowerCase()
{

	CSuperString ssToLowerCase;
	ssToLowerCase = m_pstrSuperString;

	// transform to lower case
	strlwr(ssToLowerCase.m_pstrSuperString);

	return ssToLowerCase;
}



// -------------------------------------------------------------------------------- //
// Name: TrimLeft
// Abstract: Trim off the left white space of the string
// -------------------------------------------------------------------------------- //
CSuperString CSuperString::TrimLeft()
{
	CSuperString ssTrimLeft;
	char* pstrTrimLeft = 0;
	
	
	
	return ssTrimLeft;
}



// -------------------------------------------------------------------------------- //
// Name: TrimRight
// Abstract: Trim off the right white space of the string
// -------------------------------------------------------------------------------- //
CSuperString CSuperString::TrimRight()
{
	CSuperString ssTrimRight;
	char* pstrTrimRight = 0;


	return ssTrimRight;
}



// -------------------------------------------------------------------------------- //
// Name: Trim
// Abstract: Trim the white space of the string 
// -------------------------------------------------------------------------------- //
CSuperString CSuperString::Trim()
{
	CSuperString ssTrimmed;

	ssTrimmed.TrimLeft();
	ssTrimmed.TrimRight();

	return ssTrimmed;
}



// -------------------------------------------------------------------------------- //
// Name: Reverse
// Abstract: Reverse the string
// -------------------------------------------------------------------------------- //
CSuperString CSuperString::Reverse()
{
	int intIndex = 0;
	int intAlt = 0;
	int intStringLength = 0;
	int intStringEnd = 0;
	long lngLength = Length();
	CSuperString ssReverse;
	char* pstrTempReverse = 0;

	pstrTempReverse = new char[lngLength + 1];
	
	ssReverse.CleanUp();
	
	strcpy(pstrTempReverse, m_pstrSuperString);
	for (intIndex = 0, intAlt = lngLength - 1; intIndex < intAlt; intIndex++, intAlt--)
	{
		swap(*(pstrTempReverse + intIndex), *(pstrTempReverse + intAlt));
	}
	
	ssReverse.DeepCopy(pstrTempReverse);
	
	return ssReverse;
}



// -------------------------------------------------------------------------------- //
// Name: Left
// Abstract: return from left to right number of chars
// -------------------------------------------------------------------------------- //
CSuperString CSuperString::Left(long lngCharactersToCopy)
{
	CSuperString ssLeft;
	ssLeft = Substring(0, lngCharactersToCopy);

	return ssLeft;
	
}



// -------------------------------------------------------------------------------- //
// Name: Right
// Abstract: return from right to left given number of chars
// -------------------------------------------------------------------------------- //
CSuperString CSuperString::Right(long lngCharactersToCopy)
{
	CSuperString ssRight;
	long lngLength = 0;
	int intStart = 0;

	// check your bounds
	lngLength = Length();
	
	if (lngCharactersToCopy < 0)
	{
		lngCharactersToCopy = 0;
	}
	// set number of chars to copy to length of string if number is greater than string
	if (lngCharactersToCopy > lngLength)
	{
		lngCharactersToCopy = lngLength;
	}

	// find start pos by subtracting from length of string the chars to copy (add 1 for exit)
	intStart = lngLength - lngCharactersToCopy;
	ssRight = Substring(intStart, lngCharactersToCopy);

	return ssRight;

}



// -------------------------------------------------------------------------------- //
// Name: Substring
// Abstract: Create a substring of the super string
// -------------------------------------------------------------------------------- //
CSuperString CSuperString::Substring(long lngStart, long lngSubStringLength)
{
	CSuperString ssSubString;
	char* pstrSubstring = 0;
	long lngLength = 0;

	
	// check your bounds
	lngLength = Length();
	
	if (lngSubStringLength < 0)
	{
		lngSubStringLength = 0;
	}
	
	// set number of chars to copy to length of string if number is greater than string
	if (lngSubStringLength > lngLength)
	{
		lngSubStringLength = lngLength;
	}

	// delete old substring
	DeleteString(pstrSubstring);

	
	// make some space 
	pstrSubstring = new char[lngSubStringLength + 1];

	ssSubString.CleanUp();
	
	//strncpy(pstrSubstring, (m_pstrSuperString + lngStart), lngSubStringLength);

	// use snprintf since it null terminates unlike strncpy
	snprintf(pstrSubstring, lngSubStringLength, (m_pstrSuperString + lngStart));
	ssSubString.DeepCopy(pstrSubstring);

	return ssSubString;
}



// -------------------------------------------------------------------------------- //
// Name: Replace
// Abstract: Replace specified chars with given chars
// -------------------------------------------------------------------------------- //
CSuperString CSuperString::Replace(char chrLetterToFind, char chrReplace)
{
	//*(palngValues + intIndex) = lngValue;
	return 0;
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

	if (strcmp(ToLowerCase().ToString(), "true") == 0)
	{
		blnValue = true;
	}
	
	else if (strcmp(ToLowerCase().ToString(), "1") == 0)
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
// Abstract: make a deep copy of the string- delete source, create new copy of 
// source in this instance
// -------------------------------------------------------------------------------- //
void CSuperString::DeepCopy (const char* pstrSource)
{
	char* pstrCopyOfSource = 0;
	pstrCopyOfSource = CloneString(pstrSource);
	CleanUp();
	m_pstrSuperString = pstrCopyOfSource;
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