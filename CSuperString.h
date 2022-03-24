// --------------------------------------------------------------------------------
// directives 
// --------------------------------------------------------------------------------
#ifndef CSUPER_STRING_H
#define CSUPER_STRING_H
#include <string.h>
#include <iostream>
#include "CQueue.h"

// --------------------------------------------------------------------------------
// Class: CSuperString 
// --------------------------------------------------------------------------------
class CSuperString
{
public:

protected:
	// class level properties to track pointers
	char* m_pstrSuperString;

private:


public:
	// Constructors
	CSuperString();
	CSuperString(const char* pstrStringToCopy);
	CSuperString(const bool blnBooleanToCopy);
	CSuperString(const char chrLetterToCopy);
	CSuperString(const short shtShortToCopy);
	CSuperString(const int intIntegerToCopy);
	CSuperString(const long lngLongToCopy);
	CSuperString(const float sngFloatToCopy);
	CSuperString(const double dblDoubleToCopy);
	CSuperString(const CSuperString& ssStringToCopy);

	// Destructor
	virtual ~CSuperString();

	long Length() const;

	// Assignment Operators
	CSuperString &operator = (const char chrLetterToCopy);
	CSuperString &operator = (const char* pstrStringToCopy);
	
	CSuperString &operator = (const CSuperString& ssStringToCopy);


	// Concatenate operator
	void operator += (const char* pstrStringToAppend);
	void operator += (const char chrCharacterToAppend);
	void operator += (const CSuperString& ssStringToAppend);
	
	// Extra credit for numeric parameters

	friend CSuperString operator + (const CSuperString& ssLeft,
		const CSuperString& ssRight);
	friend CSuperString operator + (const char* pstrLeftSide,
		const CSuperString& ssRightString);
	friend CSuperString operator + (const CSuperString& ssLeftString,
		const char* pstrRightSide);

	long FindFirstIndexOf(const char chrLetterToFind);
	long FindFirstIndexOf(const char chrLetterToFind, long lngStartIndex);
	long FindLastIndexOf(const char chrLetterToFind);

	long FindFirstIndexOf(const char* pstrSubStringToFind);
	long FindFirstIndexOf(const char* pstrSubStringToFind, long lngStartIndex);
	long FindLastIndexOf(const char* pstrSubStringToFind);

	CSuperString ToUpperCase();
	CSuperString ToLowerCase();
	CSuperString TrimLeft();
	CSuperString TrimRight();
	CSuperString Trim();
	CSuperString Reverse();

	
	CSuperString Left(long lngCharactersToCopy);
	CSuperString Right(long lngCharactersToCopy);
	CSuperString Substring(long lngStart, long lngSubStringLength);
	CSuperString Replace(char chrLetterToFind, char chrReplace);
	
	// Hard
	CSuperString Replace(const char* pstrFind, const char* pstrReplace);
	CSuperString Insert(const char chrLetterToInsert, long lngIndex);
	CSuperString Insert(const char* pstrSubString, long lngIndex);

	// Subscript operator
	char& operator [ ] (long lngIndex);
	const char& operator [ ] (long lngIndex) const;

	const char* ToString() const;
	bool ToBoolean();
	short ToShort();
	int ToInteger();
	long ToLong();
	float ToFloat();
	double ToDouble();
	void Print(const char* pstrCaption) const;

	friend ostream &operator << (ostream &osOut, const CSuperString& ssOutput);
	friend istream &operator >> (istream &isIn, CSuperString& ssInput);

protected:
	// Initialize
	void Initialize(const char* pstrSource);
	void DeepCopy(const char* pstrSource);
	void CleanUp();
		void DeleteString(char*& pstrSource);
	
	char* CloneString(const char* pstrSource);
	

private:

};
#endif
