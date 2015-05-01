#include <iostream>

using namespace std;

int main(int argc,  const char* argv[]) {
    if (argc < 2) {
        cout << "Too few arguments." << endl;
        return 0;
    }

    int sampleRate = stoi(argv[2]);
    int bitCount = stoi(argv[4]);
    if (bitCount != 16 && bitCount != 8) {
        cout << "Unsupported bit count." << endl;
        return 0;
    }
    int numChannels = stoi(argv[6]);
    if (numChannels != 1 && numChannels != 2) {
        cout << "Unsupported channel count." << endl;
        return 0;
    }

    int mod = 0;
    string outfileName = "out";
    if (argv[7] == "-o") {
        outfileName = argv[8];
        mod = 2;
    }

    string op = argv[7 + mod];
    string infile = "";
    if (op == "-add") {
        infile = argv[8 + mod];
    } else if (op == "-cut") {
        int r1 = stoi(argv[8 + mod]);
        int r2 = stoi(argv[9 + mod]);
        infile = argv[10 + mod];
    } else if (op == "-radd") {
        int r1 = stoi(argv[8 + mod]);
        int r2 = stoi(argv[9 + mod]);
        int s1 = stoi(argv[10 + mod]);
        int s2 = stoi(argv[11 + mod]);
        infile = argv[12 + mod];
        string infile2 = argv[13 + mod];
    } else if (op == "-cat") {
        infile = argv[8 + mod];
        string infile2 = argv[9 + mod];
    } else if (op == "-v") {
        int r1 = stoi(argv[8 + mod]);
        int r2 = stoi(argv[9 + mod]);
        infile = argv[10 + mod];
    } else if (op == "-rev") {
        infile = argv[8 + mod];
    } else if (op == "-rms") {
        infile = argv[8 + mod];
    } else if (op == "-norm") {
        int r1 = stoi(argv[8 + mod]);
        int r2 = stoi(argv[9 + mod]);
        infile = argv[10 + mod];
    } else if (op == "-fadein") {
        float s = stof(argv[8 + mod]);
        infile = argv[9 + mod];
    } else if (op == "-fadeout") {
        float s = stof(argv[8 + mod]);
        infile = argv[9 + mod];
    }

    return 0;
}
