
#include <iostream>
#include <string>
using namespace std;

const int ROWS = 13;

// function prototypes
int findRowIndex(int thisRow);
int findSeatIndex(char thisSeat);
void displaySeatColumn(char seats[][ROWS], int column);

int main()
{
	int row;
	cout << "Which row would you like to sit it? ";
	cin >> row;
	row = findRowIndex(row);
}

int findRowIndex(int thisRow)
{
	if (thisRow > ROWS || thisRow < 1)
		cout << "Error - the row you have entered is invalid.";
	else
		return thisRow - 1;
}

int findSeatIndex(char thisSeat)
{

}

void displaySeatColumn(char seats[][ROWS], int column)
{

}