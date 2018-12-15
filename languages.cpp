//Carter Mooring
//LANGUAGES (PROG8)
//languages.cpp
//cmooring
//NOV. 12th, 2018
//description: This program tests different strings to different languages
//				and determines whether the strings follow the langauges grammar
//				and prints whether it followed the grammar or not.
// Gonzaga University, CPSC 122, Dr. Yerion

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

//description: checks the string to see if it follows the grammar for the specific language
//pre: mystring, first, and last have been assigned values
//post: if mystring[first..last] follows the grammar then true is returned,
//				if not, then false is returned
//grammar:
//			<S> = $ | <W> | $ <S>
bool isS(string mystring, int first, int last);

//description: checks the string to see if it follows the grammar for the specific language
//pre: mystring, first, and last have been assigned values
//post: if mystring[first..last] follows the grammar then true is returned,
//				if not, then false is returned
//grammar:
//			<W> = abb | a<W>bb
bool isW(string mystring, int first, int last);

//description: checks the string to see if it follows the grammar for the specific language
//pre: mystring, first, and last have been assigned values
//post: if mystring[first..last] follows the grammar then true is returned,
//				if not, then false is returned
//grammar:
//				 <string> = X<body>Y | X<body> | X
//				 <body> = X | Z
bool isXYZ(string mystring, int first, int last);

//description: checks the string to see if it follows the grammar for the specific language
//pre: mystring, first, and last have been assigned values
//post: if mystring[first..last] follows the grammar then true is returned,
//				if not, then false is returned
//grammar:
//			<G> = empty string | <E> | <V><E> | <E><G><V>
bool isG(string mystring, int first, int last);

//description: checks the string to see if it follows the grammar for the specific language
//pre: mystring, first, and last have been assigned values
//post: if mystring[first..last] follows the grammar then true is returned,
//				if not, then false is returned
//grammar:
//			<E> = & | #
bool isE(string mystring, int first, int last);

//description: checks the string to see if it follows the grammar for the specific language
//pre: mystring, first, and last have been assigned values
//post: if mystring[first..last] follows the grammar then true is returned,
//				if not, then false is returned
//grammar:
//			<V> = W | A
bool isV(string mystring, int first, int last);

// prints the string to be checked
// pre: the string to check has been assigned
// post: string to check to the screen
void printOne(string mystring);

// prints the language being tested to the center of the screen
// pre: language being tested is assigned
// post: prints language to be tested to the screen
void printLanguage(string message);

// prints the result of the language tested
// pre: function for language being tested is assigned
// post: prints true or false to the screen depending on if the string followed the grammar
void printResult(bool result);

int main()
{
	printLanguage("isS and isW language");
	printOne("$");
	string mystring = "$";
	printResult(isS(mystring, 0, mystring.length()-1));
	printOne("abb");
	mystring = "abb";
	printResult(isS(mystring, 0, mystring.length()-1));
	printOne("$abb");
	mystring = "$abb";
	printResult(isS(mystring, 0, mystring.length()-1));
	printOne("abb$");
	mystring = "abb$";
	printResult(isS(mystring, 0, mystring.length()-1));
	printOne("aba");
	mystring = "aba";
	printResult(isS(mystring, 0, mystring.length()-1));
  cout << endl << endl;

	printLanguage("       isXYZ");
	printOne("X");
  mystring = "X";
	printResult(isXYZ(mystring, 0, mystring.length()-1));
	printOne("XZY");
	mystring = "XZY";
	printResult(isXYZ(mystring, 0, mystring.length()-1));
	printOne("XX");
	mystring = "XX";
	printResult(isXYZ(mystring, 0, mystring.length()-1));
	printOne("XYZ");
	mystring = "XYZ";
	printResult(isXYZ(mystring, 0, mystring.length()-1));
	printOne("Y");
	mystring = "Y";
	printResult(isXYZ(mystring, 0, mystring.length()-1));
	cout << endl << endl;

	printLanguage("isG, isE, and isV");
	printOne("&");
  mystring = "&";
	printResult(isG(mystring, 0, mystring.length()-1));
	printOne("W&");
  mystring = "W&";
	printResult(isG(mystring, 0, mystring.length()-1));
	printOne("#&A");
  mystring = "#&A";
	printResult(isG(mystring, 0, mystring.length()-1));
	printOne("D");
  mystring = "D";
	printResult(isG(mystring, 0, mystring.length()-1));
	printOne("A ");
  mystring = "A ";
	printResult(isG(mystring, 0, mystring.length()-1));
return 0;
}

//description: checks the string to see if it follows the grammar for the specific language
//pre: mystring, first, and last have been assigned values
//post: if mystring[first..last] follows the grammar then true is returned,
//				if not, then false is returned
//grammar:
//			<S> = $ | <W> | $ <S>
bool isS(string mystring, int first, int last)
{
	if(mystring.length() <= 7)
	{
		if((mystring[first] == '$') && (first == last))
		{
			return true;
		}
		else if(isW(mystring, first, last))
		{
			return true;
		}
		else if((first != last) && (mystring[first] == '$'))
		{
			return isS(mystring, first + 1, last);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//description: checks the string to see if it follows the grammar for the specific language
//pre: mystring, first, and last have been assigned values
//post: if mystring[first..last] follows the grammar then true is returned,
//				if not, then false is returned
//grammar:
//			<W> = abb | a<W>bb
bool isW(string mystring, int first, int last)
{
	if(mystring[first] == 'a')
	{
		if((mystring[first + 1] == 'b') && (mystring[first + 2] == 'b'))
		{
			if(mystring[last] == 'b')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if(mystring[first + 1] == 'a')
		{
			isW(mystring, first + 1, last);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//description: checks the string to see if it follows the grammar for the specific language
//pre: mystring, first, and last have been assigned values
//post: if mystring[first..last] follows the grammar then true is returned,
//				if not, then false is returned
//grammar:
//				 <string> = X<body>Y | X<body> | X
//				 <body> = X | Z
bool isXYZ(string mystring, int first, int last)
{
	if((first == last) && (mystring[first] == 'X'))
	{
		return true;
	}
	else
	{
		if(mystring[first] != 'X')
		{
			return false;
		}
		else
		{
			if(mystring[first + 1] == 'Y')
			{
				return false;
			}
			else
			{
				isXYZ(mystring, first + 1, last);
			}
		}
	}
}

//description: checks the string to see if it follows the grammar for the specific language
//pre: mystring, first, and last have been assigned values
//post: if mystring[first..last] follows the grammar then true is returned,
//				if not, then false is returned
//grammar:
//			<G> = empty string | <E> | <V><E> | <E><G><V>
bool isG(string mystring, int first, int last)
{
	if(first == last)
	{
		return isE(mystring, first, last);
	}
	else if(mystring.empty())
	{
		return true;
	}
	else
	{
		if(!isE(mystring, first, last) && !isV(mystring, first, last))
		{
			return false;
		}
		else if(isV(mystring, first, last))
		{
			if(isE(mystring, first + 1, last))
			{
				return isE(mystring, first + 1, last);
			}
			else
			{
				return false;
			}
		}
		else if(mystring[first] == '&' || mystring[first] == '#') //E
		{
			if(mystring[last] == 'W' || mystring[last] == 'A')		//V
			{
				isG(mystring, first + 1, last - 1);
			}
			else
			{
				return false;
			}
		}
	}
}

//description: checks the string to see if it follows the grammar for the specific language
//pre: mystring, first, and last have been assigned values
//post: if mystring[first..last] follows the grammar then true is returned,
//				if not, then false is returned
//grammar:
//			<E> = & | #
bool isE(string mystring, int first, int last)
{
	if(mystring[first] == '&' || mystring[first] == '#')
	{
		return true;
	}
	else
	{
		return false;
	}

}

//description: checks the string to see if it follows the grammar for the specific language
//pre: mystring, first, and last have been assigned values
//post: if mystring[first..last] follows the grammar then true is returned,
//				if not, then false is returned
//grammar:
//			<V> = W | A
bool isV(string mystring, int first, int last)
{
	if(mystring[first] == 'W' || mystring[first] == 'A')
	{
		return true;
	}
	else
	{
		return false;
	}
}

// prints the string to be checked
// pre: the string to check has been assigned
// post: string to check to the screen
void printOne(string mystring)
{
	cout << "String being tested: " << mystring << "          ";
}

// prints the language being tested to the center of the screen
// pre: language being tested is assigned
// post: prints language to be tested to the screen
void printLanguage(string message)
{
	cout << "                   " << message << endl << endl << endl;
}

// prints the result of the language tested
// pre: function for language being tested is assigned
// post: prints true or false to the screen depending on if the string followed the grammar
void printResult(bool result)
{
	if(result)
	{
		cout << "Result of test: true" << endl << endl;
	}
	else
	{
		cout << "Result of test: false" << endl << endl;
	}
}
