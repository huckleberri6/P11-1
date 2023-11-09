
#include <iostream>
#include <string>
using namespace std;

const int ROWS = 13;
const int COLS = 4;

// function prototypes
int findRowIndex(int thisRow);
int findSeatIndex(char thisSeat);
void displaySeatColumn(char seats[][ROWS], int column);
void displayPlane(char seats[][ROWS]);
void arr(char seats[][ROWS]);

int main()
{

	char seats[COLS][ROWS];

	for (int c = 0; c < COLS; c++)
		for (int r = 0; r < ROWS; r++)
		{
			char letter;
			if (c == 0)
				letter = 'D';
			else if (c == 1)
				letter = 'C';
			else if (c == 2)
				letter = 'B';
			else
				letter = 'A';

			seats[c][r] = letter;
		}

	arr(seats);

	cout << endl;

	int row;
	char col;
	cout << "Enter a seat or Q to quit: ";
	cin >> row >> col;
	
	while (!cin.fail())
	{

		cout << endl;

		int r = findRowIndex(row);
		int c = findSeatIndex(col);

		if (seats[col][r] == 'X')
			cout << "Error - the seat you've chosen is taken,";
		else if (r == 13 && (c == 0 || c == 1))
			cout << "Error - you cannot sit in the lavatory.";
		else
			seats[c][r] = 'X';

		arr(seats);

		cout << endl;

		cout << "Enter a seat or Q to quit: ";
		cin >> row >> col;
	}
}

int findRowIndex(int thisRow)
{
	if (thisRow > ROWS || thisRow < 1)
		cout << "Error - the row you have entered is invalid.";
	else
		return thisRow - 1;

	return -1;
}

int findSeatIndex(char thisSeat)
{
	cout << "thisSeat: " << thisSeat << endl;

	if (thisSeat == 'D')
		return 0;
	else if (thisSeat == 'C')
		return 1;
	else if (thisSeat == 'B')
		return 2;
	else if (thisSeat == 'A')
		return 3;
	else
		cout << "Error - the seat column you have entered is invalid." << endl;

	return -1;
}

void arr(char seats[][ROWS])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 12; j++)
			cout << seats[i][j] << " ";
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 13; i++)
		if (i < 9)
			cout << "  ";
		else
			cout << "1 ";

	cout << endl;

	for (int c = 1; c < 14; c++)
		if (c < 10)
			cout << c << " ";
		else
			cout << c % 10 << " ";

	cout << endl;
	cout << endl;

	for (int i = 2; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
			cout << seats[i][j] << " ";
		cout << endl;
	}
}

void displayPlane(char seats[][ROWS])
{
	displaySeatColumn(seats, 0);
	cout << endl;
	displaySeatColumn(seats, 1);

	cout << endl;
	cout << endl;

	for (int i = 0; i < 13; i++)
		if (i < 9)
			cout << "  ";
		else
			cout << "1 ";

	cout << endl;

	for (int c = 0; c < 13; c++)
		if (c < 10)
			cout << c << " ";
		else
			cout << c % 10 << " ";

	cout << endl;
	cout << endl;
	
	displaySeatColumn(seats, 2);
	cout << endl;
	displaySeatColumn(seats, 3);

	cout << endl;
}

void displaySeatColumn(char seats[][ROWS], int column)
{
	cout << "column: " << column << endl;

	int size;
	if (column < 2)
		size = 12;
	else
		size = 13;

	for (int i = 0; i < size; i++)
	{
		cout << seats[column][ROWS] << " ";
	}
}