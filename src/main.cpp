#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
#include "jfs.h"

using namespace std;

void bits_to_hex(string sin) {
	if (!sin.size()) {
		cout << "Error: empty string." << endl;
		cout << "Please provide a value of the form 1101001..." << endl;
		return;
	}
	static bool display_title {1};
	if (display_title) {
		cout << setw(16) << "Bits      " << setw(11) << "Bit" << setw(4) << "Hex" << endl;
		display_title = 0;
	}
	
	unsigned int value {0};
	int exp {0};

	for (int i = sin.size() - 1; i >= 0 ; i--) {
		if (sin[i] != '0' && sin[i] != '1') {
			cout << "Error: wrong char." << endl;
			cout << "Please provide a value of the form 1101001..." << endl;
			cout << "Note: We have received this char >> " << sin[i] << endl;
			return;
		} else {
			if (sin[i] == '1') {
			value += pow(2, exp);
			}
			exp++;
		}
	}
	cout << setw(16) << bitset<16>(value) << setw(11) << log2(value) << setw(4) << "(0x" << std::hex << value << ")" << endl;
}

int main(int argc, char** argv) {
	vector<string> args {args_read(argc, argv)};
	if (args.size() > 1) {
		for (auto i:args) {
			static int count {0}; // Pass 1st arg. (filename)
			if (count++)
				bits_to_hex(i);
		}

	}
	else {
		cout << endl;
		cout << "Usage: ./bits 1101010 111 01100110 11010101" << endl;
		cout << endl;
		cout << "./bits 0 1 10 11 100" << endl;
		bits_to_hex("0");
		bits_to_hex("1");
		bits_to_hex("10");
		bits_to_hex("11");
		bits_to_hex("100");
		cout << endl;
	}
}
