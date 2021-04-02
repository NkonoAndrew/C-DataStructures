#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;
const int size = 10000, histSize = 500;

unsigned int collisionCounts1[size] = {0};
unsigned int collisionCounts2[size] = {0};
unsigned int collisionCounts3[size] = {0};
unsigned int collisionCounts4[size] = {0};
int histogram1[histSize] = {0};
int histogram2[histSize] = {0};
int histogram3[histSize] = {0};
int histogram4[histSize] = {0};

unsigned int myHash1(const string &  s, int size) {
	unsigned int h = 0;
	for (int i = 0; i < s.length(); i++)
		h = h + s[i]; // just add the ASCII values
	return h % size ;
}


unsigned int myHash2(const string &  s, int size) {
	unsigned int h = 0;
	const int b = 2; // a multiplier that that's too small and has common factors with size
	for (int i = 0; i < s.length(); i++) {
		h *= b;
		h += (s[i] - 'a');  // add the next letter value
		h %= size;
	}
	return h ;
}



unsigned int myHash3(const string &  s, int size) {
	unsigned int h = 0;
	const int b = 26; // a bigger multiplier but not coprime with size
	for (int i = 0; i < s.length(); i++) {
		h *= b;
		h += (s[i] - 'a'); // add the next letter value
		h %= size;
	}

	return h;
}

unsigned int myHash4(const string &  s, int size) {
	unsigned int h = 0;
	const int b = 29; // a prime multiplier and >= number of letters
	for (int i = 0; i < s.length(); i++) {
		h *= b;
		h += (s[i] - 'a'); // add the next letter value
		h %= size;
	}

	return h;
}


void printHistogram(int histogram[], int length) {
	cout << left;
	cout << "Histogram shows count of buckets with exactly k items." << endl; 
	cout << setw(5) << "k" << setw(5) << "#" << endl;
	for (int i = 0; i < length/12; i++) {
		cout << setw(5) << i;
		cout << setw(5) << histogram[i];
		for (int j = 0; j < int(histogram[i]/15.0 + 0.5); j++) 
				cout << "*";
		cout << endl;
	}
	cin.get();
	int lasti = length/12-1;
	for (int i = length/12; i< length; i++) 
			if (histogram[i] > 0) {
				if (lasti != i-1) cout << "..." << endl;
				cout << setw(5) << i;
				cout << setw(5) << histogram[i] << endl;
				lasti = i;
			}

}

void printArray(int nums[], int length) {
	for (int i = 0; i < length; i++)
		cout << nums[i] << " ";
	cout << endl;
}

void normalize(string & s) {
    string t = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] <= 'Z' && s[i] >= 'A')     s[i] += ('a' - 'A');
        if (s[i] <= 'z' && s[i] >= 'a')     t+= s[i];
    }
    s = t;
}


int main() {
	ifstream in; 
	in.open("words.txt");
	string s;
	int count = 0;
	while (in) {
		in >> s;
		normalize(s);
		if (in) {
			count++;
			collisionCounts1[myHash1(s,size)]++;
			collisionCounts2[myHash2(s,size)]++;
			collisionCounts3[myHash3(s,size)]++;
			collisionCounts4[myHash4(s,size)]++;
		}
	}
	cout << count << " words read in " << endl;
	for (int i = 0; i < size; i++) {
		histogram1[collisionCounts1[i]]++;
		histogram2[collisionCounts2[i]]++;
		histogram3[collisionCounts3[i]]++;
		histogram4[collisionCounts4[i]]++;
	}
	
	printHistogram(histogram1,histSize);
	cout << endl << endl; cin.get();
	printHistogram(histogram2,histSize);
	cout << endl << endl; cin.get();
	printHistogram(histogram3,histSize);
	cout << endl << endl; cin.get();
	printHistogram(histogram4,histSize);
	cout << endl << endl; cin.get();

	cout << "bye" << endl;


	return 0;
}


	

