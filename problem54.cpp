#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool hascard(string hand[], char value) {
	for (int i = 0; i < 5; i++)
		if (hand[0][0] == value)
			return true;
	return false;
}

int card2value(char card) {
	if (card == 'A')
		return 14;
	if (card == 'K')
		return 13;
	if (card == 'Q')
		return 12;
	if (card == 'J')
		return 11;
	if (card == 'T')
		return 10;
	if (card == '9')
		return 9;
	if (card == '8')
		return 8;
	if (card == '7')
		return 7;
	if (card == '6')
		return 6;
	if (card == '5')
		return 5;
	if (card == '4')
		return 4;
	if (card == '3')
		return 3;
	if (card == '2')
		return 2;
	return -100;
}

char value2card(int value) {
	if (value == 14)
		return 'A';
	if (value == 13)
		return 'K';
	if (value == 12)
		return 'Q';
	if (value == 11)
		return 'J';
	if (value == 10)
		return 'T';
	if (value == 9)
		return '9';
	if (value == 8)
		return '8';
	if (value == 7)
		return '7';
	if (value == 6)
		return '6';
	if (value == 5)
		return '5';
	if (value == 4)
		return '4';
	if (value == 3)
		return '3';
	if (value == 2)
		return '2';
	return 'X';
}

bool samesuit(string hand[]) {
	char suit = hand[0][1];
	for (int i = 1; i < 5; i++) {
		if (suit != hand[i][1])
			return false;
	}
	return true;
}

int highestvalue(string hand[]) {
	int highest = 0;
	for (int i = 0; i < 5; i++) {
		if (card2value(hand[i][0]) > highest)
			highest = card2value(hand[i][0]);
	}
	return highest;
}

int smallestvalue(string hand[]) {
	int smallest = 0;
	for (int i = 0; i < 5; i++) {
		if (card2value(hand[i][0]) < smallest && hand[i][0] != 'X')
			smallest = card2value(hand[i][0]);
	}
	return smallest;
}

int flush(string hand[]) {
	if (samesuit(hand)) {
		return highestvalue(hand);
	}
	return 0;
}

void swap(string hand[], int a, int b) {
	string temp = hand[a];
	hand[a] = hand[b];
	hand[b] = temp;
}

void inversebubblesort(string hand[]) {
    bool foundnew = true;
    int length = 5;
    while (foundnew) {
        foundnew = false;
        for (int i = 0; i < length-1; i++) {
            if (card2value(hand[i+1][0]) > card2value(hand[i][0])) {
                swap(hand,i,i+1);
                foundnew = true;
            }
        }
        length--;
    }
}

int straight(string hand[]) {
	inversebubblesort(hand);
	if (hand[0][0] == 'A') {
		if (hand[1][0] == 'K' && hand[2][0] == 'Q' && hand[3][0] == 'J' && hand[4][0] == 'T')
			return 14;
		if (hand[1][0] == '5' && hand[2][0] == '4' && hand[3][0] == '3' && hand[4][0] == '2')
			return 5;
		return 0;
	}
	else {
		int a = card2value(hand[0][0]);
		for (int i = 1; i < 5; i++) {
			if (card2value(hand[i][0]) != a-i)
				return 0;
		}
		return a;	
	}
	return 0;
}

bool royalflush(string hand[]) {
	if (straight(hand) && flush(hand) && hascard(hand, 'A') && hascard(hand, 'K'))
		return true;
	return false;
}

int straightflush(string hand[]) {
	if (straight(hand) && flush(hand))
		return straight(hand);
	return 0;
}

int ofakind(string hand[], int n, bool remove = false) {
	int array[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	for (int i = 0; i < 5; i++) {
		if (hand[i][0] != 'X')
			array[card2value(hand[i][0])-2]++;
	}
	for (int i = 0; i < 13; i++) {
		if (array[i] == n) {
			if (remove)
				for (int j = 0; j < 5; j++)
					if (card2value(hand[i][0])-2 == i)
						hand[j] = "XX";
			return i+2;
		}
	}
	return 0;
}

bool twopairs(string hand[], bool remove = false) {
	int array[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	for (int i = 0; i < 5; i++) {
		array[card2value(hand[i][0])-2]++;
	}
	int count = 0;
	for (int i = 0; i < 13; i++) {
		if (array[i] == 2) {
			count++;
			if (remove) {
				for (int j = 0; j < 5; j++)
					if (card2value(hand[j][0])-2 == i)
						hand[j] = "XX";
			}
		}
	}
	return (count == 2);
}

int fullhouse(string hand[]) {
	if (ofakind(hand,3) && ofakind(hand,2)) {
		return ofakind(hand,3);
	}
	return 0;
}

int highest(string hand1[], string hand2[]) {
	inversebubblesort(hand1);
	inversebubblesort(hand2);
	for (int i = 0; i < 5; i++) {
		if (card2value(hand1[i][0]) < card2value(hand2[i][0]))
			return 0;
		if (card2value(hand1[i][0]) > card2value(hand2[i][0]))
			return 1;
	}
	return 0;
}

int winner(string hand1[], string hand2[]) {
	if (royalflush(hand1))
		return 1;
	if (royalflush(hand2)) 
		return 0;
	
	if (straightflush(hand1) || straightflush(hand2)) {
		if (straightflush(hand1) > straightflush(hand2))
			return 1;
		return 0;
	}
	
	if (ofakind(hand1,4) || ofakind(hand2, 4)) {
		if (ofakind(hand1,4) > ofakind(hand2,4))
			return 1;
		else if (ofakind(hand1,4) < ofakind(hand2,4))
			return 0;
		else {
			ofakind(hand1,4,true);
			ofakind(hand2,4,true);
			return highest(hand1,hand2);
		}
	}
	
	if (fullhouse(hand1) || fullhouse(hand2)) {
		if (fullhouse(hand1) > fullhouse(hand2))
			return 1;
		else if (fullhouse(hand1) < fullhouse(hand2))
			return 0;
		else {
			ofakind(hand1,3,true);
			ofakind(hand2,3,true);
			if (ofakind(hand1,2) > ofakind(hand2,2))
				return 1;
			else
				return 0;
		}
	} 
	
	if (flush(hand1) || flush(hand2)) { 
		if (flush(hand1) > flush(hand2))
			return 1;
		else if (flush(hand1) < flush(hand2))
			return 0;
		else {
			return highest(hand1, hand2);
		}
		return 0;
	}
	
	if (straight(hand1) || straight(hand2)) { 
		if (straight(hand1) > straight(hand2))
			return 1;
		return 0;		
	}
	
	if (ofakind(hand1,3) || ofakind(hand2, 3)) {
		if (ofakind(hand1,3) > ofakind(hand2,3))
			return 1;
		else if (ofakind(hand1,3) < ofakind(hand2,3))
			return 0;
		else {
			ofakind(hand1,3,true);
			ofakind(hand2,3,true);
			return highest(hand1,hand2);
		}
	}
	
	if (twopairs(hand1) || twopairs(hand2)) {
		if (twopairs(hand1) > twopairs(hand2))
			return 1;
		else if (twopairs(hand1) < twopairs(hand2))
			return 0;
		else {
			twopairs(hand1,true);
			twopairs(hand2,true);
			return highest(hand1,hand2);
		}
	}
	
	if (ofakind(hand1,2) || ofakind(hand2, 2)) {
		if (ofakind(hand1,2) > ofakind(hand2,2))
			return 1;
		else if (ofakind(hand1,2) < ofakind(hand2,2))
			return 0;
		else {
			ofakind(hand1,2,true);
			ofakind(hand2,2,true);
			return highest(hand1,hand2);
		}
	}

	return highest(hand1,hand2);
}

int main() {
	ifstream pokerfile("poker.txt");
	int count = 0;
	if (pokerfile) {
		for (int j = 0; j < 1000; j++) {
			string hand1[5];
			string hand2[5];
			for (int i = 0; i < 5; i++)
				pokerfile >> hand1[i];
			for (int i = 0; i < 5; i++)
			pokerfile >> hand2[i];
			count += winner(hand1,hand2);
		}
	}
	else {
		cout << "Failed opening file";
	}
	cout << count;
	return 0;
}