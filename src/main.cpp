//******************************************************************************
// File name:   main.cpp
// Author:      CS Faculty
// Date:        xx/xx/xxxx (Replace xx/xx/xxxx with month/day/year)
// Class:       CS150-xx (Replace xx with your section number)
// Assignment:  Hello World
// Purpose:     Display the message Hello World to the screen
// Hours:       0.25
//******************************************************************************

#include <iostream>
#include <math.h>

using namespace std;

int hexCharToInt (char hexDigit);

char getBase (const string& strNumber);

string getNumber (const string& prompt);

void printTitle (const string& myTitle);

string binaryToDecimal (const string& strNumber);

string decimalToBinary (const string& strNumber);

string decimalToHex (const string& strNumber);

string hexToDecimal (const string& strNumber);

string hexToBinary (const string& strNumber);

string binaryToHex (const string& strNumber);

int main () {

  cout << "Hello World" << endl;
  cout << hexToDecimal(decimalToHex("0")) << endl;
  cout << hexToDecimal(decimalToHex("255")) << endl;
  cout << hexToDecimal(decimalToHex("65536")) << endl;
  cout << hexToDecimal(decimalToHex("283754")) << endl;
  return EXIT_SUCCESS;
}

int hexCharToInt (char hexDigit)
{
  hexDigit = toupper (hexDigit);
  if (isalpha (hexDigit))
  {
    return hexDigit - 55;
  }
  else
  {
    return hexDigit - 48;
  }
}

char getBase (const string& strNumber)
{
  switch (strNumber[1])
  {
    case 'x':
      return 'H';
    case 'b':
      return 'B';
    default:
      return 'D';
  }
}

string getNumber (const string& prompt)
{
  string returnString;

  cout << prompt;
  cin >> returnString;

  return returnString;
}

void printTitle (const string& myTitle)
{
  cout << myTitle << endl;
}

string binaryToDecimal (const string& strNumber)
{
  int numDigits = strNumber.length ();
  int sum = 0;
  
  int power = 0;

  for (int i = numDigits - 1; i >= 0; i--)
  {
    if (strNumber[i] == '1')
    {
      sum += pow(2,power);
    }
    power++;
  }

  return to_string (sum);
}

string decimalToBinary (const string& strNumber)
{
  int decimalNumber = stoi(strNumber);
  string binaryString = "";
  do
  {
    binaryString = to_string(decimalNumber % 2) + binaryString;
    decimalNumber = decimalNumber / 2;
  } while (decimalNumber != 0);
  return binaryString;
}

string decimalToHex (const string& strNumber)
{
  const string ARRAY_HEX_DIGITS[16] = {"0", "1", "2", "3", "4", "5", "6", "7", 
                                       "8", "9", "A", "B", "C", "D", "E", "F"};
  
  int decimalNumber = stoi(strNumber);
  string hexString = "";
  do
  {
    hexString = ARRAY_HEX_DIGITS[decimalNumber % 16] + hexString;
    decimalNumber = decimalNumber / 16;
  } while (decimalNumber != 0);
  return hexString;
}

string hexToDecimal (const string& strNumber)
{
  int numDigits = strNumber.length ();
  int sum = 0;
  
  int power = 0;

  for (int i = numDigits - 1; i >= 0; i--)
  {
    sum += pow(16,power) * hexCharToInt(strNumber[i]);
    power++;
  }

  return to_string (sum);
}

string hexToBinary (const string& strNumber)
{
  return decimalToBinary(hexToDecimal(strNumber));
}

string binaryToHex (const string& strNumber)
{
  return decimalToHex(binaryToDecimal(strNumber));
}