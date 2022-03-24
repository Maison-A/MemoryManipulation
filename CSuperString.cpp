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
	long lngLength = Length();

	// make space for new char*
	pstrAppendedString = new char[lngLength + 2];
	
	// copy the original instance to new pitner
	strcpy((pstrAppendedString), m_pstrSuperString);
	
	// set copied value's final index to appended char
	pstrAppendedString[lngLength] = chrCharacterToAppend;

	// null terminate
	pstrAppendedString[lngLength + 1] = '\0';

	// clean up old instance
	CleanUp();

	// deep copy new instance 
	DeepCopy(pstrAppendedString);
	
}



// -------------------------------------------------------------------------------- //
// Name: operator += 
// Abstract: Concatenate operator
// -------------------------------------------------------------------------------- //
void CSuperString::operator += (const CSuperString &ssStringToAppend)
{
	char* pstrAppendedString = 0;
	long lngIndex = 0;
	long lngLength = Length();
	long lngToAppendLength = ssStringToAppend.Length();
	char array1[] = "The dog jumps ";
	char array2[] = "over the log";
	pstrAppendedString = new char[lngLength + lngToAppendLength + 1];
	strcpy(pstrAppendedString, m_pstrSuperString);
	strcat(pstrAppendedString, ssStringToAppend.m_pstrSuperString);

	CleanUp();
	DeepCopy(pstrAppendedString);

}


// -------------------------------------------------------------------------------- //
// Name: 
// Abstract: 
// -------------------------------------------------------------------------------- //	
CSuperString operator + (const CSuperString& ssLeft, const CSuperString& ssRight)
{
	CSuperString ssNew;
	ssNew.CleanUp();
	ssNew = strcat(ssLeft.m_pstrSuperString, ssRight.m_pstrSuperString);

	return ssNew;
}




// -------------------------------------------------------------------------------- //
// Name: 
// Abstract: 
// -------------------------------------------------------------------------------- //	
CSuperString operator + (const char* pstrLeftSide, const CSuperString& ssRightString)
{
	CSuperString ssNew;
	ssNew.CleanUp();
	ssNew.DeepCopy(pstrLeftSide);

	strcat(ssNew.m_pstrSuperString, ssRightString.m_pstrSuperString);

	return ssNew;
}




// -------------------------------------------------------------------------------- //
// Name: 
// Abstract: 
// -------------------------------------------------------------------------------- //	
CSuperString operator + (const CSuperString& ssLeftString, const char* pstrRightSide)
{
	CSuperString ssTemp;
	CSuperString ssNew;
	ssTemp.CleanUp();

	ssTemp.DeepCopy(pstrRightSide);
	ssNew.DeepCopy(ssLeftString.m_pstrSuperString);
	strcat(ssNew.m_pstrSuperString, ssTemp.m_pstrSuperString);

	return ssNew;
}


// -------------------------------------------------------------------------------- //
// Name: operator <<
// Abstract: inject superstring into the string buffer
// -------------------------------------------------------------------------------- //
ostream& operator << (ostream& osOut, const CSuperString& ssOutput)
{
	osOut.write(ssOutput.ToString(), ssOutput.Length());

	return osOut;
}


// -------------------------------------------------------------------------------- //
// Name: operator >>
// Abstract: 
// -------------------------------------------------------------------------------- //
istream& operator >> (istream& isIn, CSuperString& ssInput)
{
	isIn.getline(ssInput.m_pstrSuperString, ssInput.Length());

	return isIn;
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
			// break on first found index
			break;
		}
	}

	return lngIndexOf;
}



// -------------------------------------------------------------------------------- //
// Name: FindFirstIndexOf
// Abstract: find index of given char after specific index
// -------------------------------------------------------------------------------- //
long CSuperString::FindFirstIndexOf(const char chrLetterToFind, long lngStartIndex)
{
	long lngIndexOf = 0;
	long lngLength = Length();
	
	for (int intIndex = lngStartIndex; intIndex <= lngLength; intIndex++)
	{
		if (*(this->m_pstrSuperString + intIndex) == chrLetterToFind)
		{
			lngIndexOf = intIndex;
			// break once first index is found
			break;
		}
	}

	return lngIndexOf;
}



// -------------------------------------------------------------------------------- //
// Name: FindLastIndexOf
// Abstract: Find the first index of a character given
// -------------------------------------------------------------------------------- //
long CSuperString::FindLastIndexOf(const char chrLetterToFind)
{
	long lngIndexOf = 0;
	long lngLength = Length();

	for (int intIndex = lngLength; intIndex >= 0; intIndex--)
	{
		if (*(m_pstrSuperString + intIndex) == chrLetterToFind)
		{
			lngIndexOf = intIndex;
			// ignore break and continue returning latest index
		}
	}

	return lngIndexOf;
}



// -------------------------------------------------------------------------------- //
// Name: FindFirstIndexOf
// Abstract: find and return the first index of the given substring
// -------------------------------------------------------------------------------- //
long CSuperString::FindFirstIndexOf(const char* pstrSubStringToFind)
{
	long lngFirstIndexOf = 0;
	int intIndex = 0;
	long lngFirstCharToFindIndex = 0;
	long lngLastCharToFindIndex = 0;

	long lngSubstringStartIndex = 0;
	long longSubstringEndIndex = 0;
	
	long lngLength = Length();
	long lngSubStringLength = 0;
	
	char* pstrFirstLetterOfSubstring;
	
	
	CSuperString ssBuffer;
	CSuperString ssBuffer2;

	
	// clean up old mem 
	ssBuffer.CleanUp();
	
	// set buffer as string
	ssBuffer.DeepCopy(m_pstrSuperString);
	
	// clean up old mem
	ssBuffer2.CleanUp();

	// set size of first letter to find
	pstrFirstLetterOfSubstring = new char[2];

	// get first letter of pstrSubstringToFind
	strncpy(pstrFirstLetterOfSubstring, pstrSubStringToFind, 1);
	
	// find first index of that letter in the string - set that index as start index
	lngFirstCharToFindIndex = ssBuffer.FindFirstIndexOf(*pstrFirstLetterOfSubstring);

	// find index of final letter in string - set as end index
	lngLastCharToFindIndex = (strlen(pstrSubStringToFind) + 1);

	ssBuffer2 = ssBuffer.Substring(lngFirstCharToFindIndex, lngLastCharToFindIndex);
	
	// cout << "test: " << ssBuffer2.ToString();
	// check if substrings match - if not return error message and set to 0
	if (strcmp(ssBuffer2.m_pstrSuperString, pstrSubStringToFind) == 0)
	{
		lngFirstIndexOf = lngFirstCharToFindIndex;
	}
	else
	{
		cout << "COULD NOT FIND SUBSTRING GIVEN" << endl;
		lngFirstIndexOf = 0;
	}
	ssBuffer.CleanUp();
	ssBuffer2.CleanUp();

	delete[] pstrFirstLetterOfSubstring;
	pstrFirstLetterOfSubstring = 0;


	
	return lngFirstIndexOf;
}



// -------------------------------------------------------------------------------- //
// Name: FindFirstIndexOf
// Abstract: 
// -------------------------------------------------------------------------------- //
long CSuperString::FindFirstIndexOf(const char* pstrSubStringToFind, long lngStartIndex)
{
	long lngFirstIndexOf = 0;
	int intIndex = 0;
	long lngFirstCharToFindIndex = 0;
	long lngLastCharToFindIndex = 0;

	long lngSubstringStartIndex = 0;
	long longSubstringEndIndex = 0;

	long lngLength = Length();
	long lngSubStringLength = 0;

	char* pstrFirstLetterOfSubstring;


	CSuperString ssBuffer;
	CSuperString ssBuffer2;


	// clean up old mem 
	ssBuffer.CleanUp();

	// set buffer as string
	ssBuffer.DeepCopy(m_pstrSuperString);

	// clean up old mem
	ssBuffer2.CleanUp();

	// set size of first letter to find
	pstrFirstLetterOfSubstring = new char[2];

	// get first letter of pstrSubstringToFind
	strncpy(pstrFirstLetterOfSubstring, pstrSubStringToFind, 1);

	// find first index of that letter in the string - set that index as start index
	lngFirstCharToFindIndex = ssBuffer.FindFirstIndexOf(*pstrFirstLetterOfSubstring, lngStartIndex);

	// find index of final letter in string - set as end index
	lngLastCharToFindIndex = (strlen(pstrSubStringToFind) + 1);

	ssBuffer2 = ssBuffer.Substring(lngFirstCharToFindIndex, lngLastCharToFindIndex);

	// cout << "test: " << ssBuffer2.ToString();
	// check if substrings match - if not return error message and set to 0
	
		if (strcmp(ssBuffer2.m_pstrSuperString, pstrSubStringToFind) == 0)
		{
			lngFirstIndexOf = lngFirstCharToFindIndex;
		}
		else
		{
			cout << "COULD NOT FIND SUBSTRING GIVEN" << endl;
			lngFirstIndexOf = 0;
		}

	
	ssBuffer.CleanUp();
	ssBuffer2.CleanUp();

	delete[] pstrFirstLetterOfSubstring;
	pstrFirstLetterOfSubstring = 0;



	return lngFirstIndexOf;
}



// -------------------------------------------------------------------------------- //
// Name: FindLastIndexOf
// Abstract: 
// -------------------------------------------------------------------------------- //
long CSuperString::FindLastIndexOf(const char* pstrSubStringToFind)
{
	long lngFirstIndexOf = 0;
	int intIndex = 0;
	long lngFirstCharToFindIndex = 0;
	long lngLastCharToFindIndex = 0;

	long lngSubstringStartIndex = 0;
	long longSubstringEndIndex = 0;

	long lngLength = Length();
	long lngSubStringLength = 0;

	char* pstrFirstLetterOfSubstring;


	CSuperString ssBuffer;
	CSuperString ssBuffer2;


	// clean up old mem 
	ssBuffer.CleanUp();

	// set buffer as string
	ssBuffer.DeepCopy(m_pstrSuperString);

	// clean up old mem
	ssBuffer2.CleanUp();

	// set size of first letter to find
	pstrFirstLetterOfSubstring = new char[2];

	// get first letter of pstrSubstringToFind
	strncpy(pstrFirstLetterOfSubstring, pstrSubStringToFind, 1);

	// find first index of that letter in the string - set that index as start index
	lngFirstCharToFindIndex = ssBuffer.FindLastIndexOf(*pstrFirstLetterOfSubstring);

	// find index of final letter in string - set as end index
	lngLastCharToFindIndex = (strlen(pstrSubStringToFind) + 1);

	ssBuffer2 = ssBuffer.Substring(lngFirstCharToFindIndex, lngLastCharToFindIndex);

	// cout << "test: " << ssBuffer2.ToString();
	// check if substrings match - if not return error message and set to 0

	if (strcmp(ssBuffer2.m_pstrSuperString, pstrSubStringToFind) == 0)
	{
		lngFirstIndexOf = lngFirstCharToFindIndex;
	}
	else
	{
		cout << "COULD NOT FIND SUBSTRING GIVEN" << endl;
		lngFirstIndexOf = 0;
	}


	ssBuffer.CleanUp();
	ssBuffer2.CleanUp();

	delete[] pstrFirstLetterOfSubstring;
	pstrFirstLetterOfSubstring = 0;



	return lngFirstIndexOf;
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
	// TODO
	CSuperString ssTrimLeft;

	
	
	
	return ssTrimLeft;
}



// -------------------------------------------------------------------------------- //
// Name: TrimRight
// Abstract: Trim off the right white space of the string
// -------------------------------------------------------------------------------- //
CSuperString CSuperString::TrimRight()
{
	// TODO
	CSuperString ssTrimRight;


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
	
	ssSubString.CleanUp();
	
	// delete old substring
	DeleteString(pstrSubstring);

	// make some space 
	pstrSubstring = new char[lngSubStringLength + 1];
	

	// use snprintf since it null terminates unlike strncpy
	//strncpy(pstrSubstring, (m_pstrSuperString + lngStart), lngSubStringLength);
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
	CSuperString ssReplace;
	long lngIndexOfChar = 0;
	char* pstrTemp = CloneString(m_pstrSuperString);
	// clear any previous class data
	ssReplace.CleanUp();
	// deep copy the original super string to manipulate
	ssReplace.DeepCopy(m_pstrSuperString);
	
	// loop and find/replace every instance of given character
	for (int intIndex = 0; intIndex <= Length(); intIndex++)
	{
		lngIndexOfChar = FindFirstIndexOf(chrLetterToFind, intIndex);
	
		if (*(ssReplace.m_pstrSuperString + intIndex) == chrLetterToFind)
		{
			*(ssReplace.m_pstrSuperString + intIndex) = chrReplace;
		}
	}
	delete[] pstrTemp;
	pstrTemp = 0;

	return ssReplace;
}



// -------------------------------------------------------------------------------- //
// Name: Replace
// Abstract: Replace specified char* with new values: 
// I want to take the "original" (so deep copy) - find the index of the substring
// to find, use it's length to replace/strcpy from that index to the end while preserving
// the rest of the string. 
// If i want to preserve the rest of the string - i'll have to append the second half of the string 
// after i'm done replaciong the string to find.
// so - create a pointer, copy the class string up to the end of the str to find's last char (len)
// then, create another pointer starting from the end of string to replaces length.
// then append the two pointers and return as ssReplace
// -------------------------------------------------------------------------------- //
CSuperString CSuperString::Replace(const char* pstrFind, const char* pstrReplace)
{
	// reference super string
	CSuperString ssReference;
	// first half of string
	CSuperString ssStartBuffer;
	// chunk of string to replace
	CSuperString ssImportantPart;	
	// last half of string
	CSuperString ssEndBuffer; 
	// changed total string
	CSuperString ssChangedString;
	// string to concatinate then deep copy into final changed super string
	char* pstrFinalString = 0;

	// indices and lengths
	long lngIndexToStart = 0;
	long lngIndexOfChar = 0;
	long lngIndexOfToFind = 0;
	long lngToFindLength = strlen(pstrFind);
	long lngToReplaceLength = strlen(pstrReplace);
	long lngSubstringStartIndex = 0;
	long lngTotalLength = 0;
	// clean up then deep copy to reference string super string
	ssReference.CleanUp();
	ssReference.DeepCopy(m_pstrSuperString);
	
	// clean up all old or remaining class data
	ssStartBuffer.CleanUp();
	ssImportantPart.CleanUp();
	ssEndBuffer.CleanUp();
	ssChangedString.CleanUp();

	// find index to start first half of string
	lngIndexToStart = ssReference.FindFirstIndexOf(pstrFind);

	// copy up to index to find
	ssStartBuffer = ssReference.Substring(0, lngIndexToStart);
	//strncpy(ssStartBuffer.m_pstrSuperString, ssReference.m_pstrSuperString, lngIndexToStart);

	// now we have StartBuffer set as first half of string up to string to find
	// time to copy the string to find in it's own buffer
	//strcpy(ssImportantPart.m_pstrSuperString, pstrFind);
	ssImportantPart.DeepCopy(pstrFind);

	// start buffer and old string to change are now in their own buffers - time to get the last half
	// going to have to set as a substring - but to get a starting position, we need to 
	// find the total length of the first two strings
	lngSubstringStartIndex = strlen(ssStartBuffer.m_pstrSuperString) + strlen(ssImportantPart.m_pstrSuperString);
	
	// use length of reference string as end index
	ssEndBuffer = ssReference.Substring(lngSubstringStartIndex, strlen(ssReference.m_pstrSuperString));

	// now replace old string buffer value to string to replace 
	//strcpy(ssImportantPart.m_pstrSuperString, pstrReplace);
	ssImportantPart.DeepCopy(pstrReplace);

	// find total length of all values and set space for final string to be deep copied
	lngTotalLength = strlen(ssStartBuffer.m_pstrSuperString) + strlen(ssImportantPart.m_pstrSuperString) + strlen(ssEndBuffer.m_pstrSuperString);
	pstrFinalString = new char[lngTotalLength + 1];
	strcpy(pstrFinalString, ssStartBuffer.m_pstrSuperString);
	strcat(pstrFinalString, ssImportantPart.m_pstrSuperString);
	strcat(pstrFinalString, ssEndBuffer.m_pstrSuperString);

	ssChangedString.DeepCopy(pstrFinalString);
	// now we have all values in their own safe buffers, time to compile them all into one super string
	//ssChangedString.DeepCopy(ssStartBuffer.m_pstrSuperString);
	//strcat(ssChangedString.m_pstrSuperString, ssImportantPart.m_pstrSuperString);
	//strcat(ssChangedString.m_pstrSuperString, ssEndBuffer.m_pstrSuperString);

	// clean up
	ssStartBuffer.CleanUp();
	ssImportantPart.CleanUp();
	ssEndBuffer.CleanUp();

	delete[] pstrFinalString;
	pstrFinalString = 0;

	return ssChangedString;
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