#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Function to read the input file and return a vector of strings (each line is
// an element in the vector)
void readInput(vector<int> &a, vector<int> &b, const string &filename) {
  ifstream inputFile(filename);

  if (!inputFile) {
    cerr << "Error: Could not open the file " << filename << endl;
  }
  string line;

  string point;

  while (getline(inputFile, line)) {

    stringstream s(line);
    s >> point;
    a.push_back(stoi(point));
    s >> point;
    b.push_back(stoi(point));
  }

  cout << a.size() << endl;
  cout << b.size() << endl;
  inputFile.close();
}

// Placeholder for solving the problem
int solve(vector<int> a, vector<int> b) {
  unordered_map<int, int> a_freq;
  for (int x : a) {
    if (a_freq[x]) {
      a_freq[x] += 1;
    } else {
      a_freq[x] = 1;
    }
  }
  int res = 0;
  for (int y : b) {
    res += y * a_freq[y];
  }
  return res;
}

int main(int argc, char *argv[]) {
  // Check if the filename is provided
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <input_file>" << endl;
    return 1;
  }

  string filename = argv[1];
  vector<int> a;
  vector<int> b;
  readInput(a, b, filename);

  cout << solve(a, b) << endl;

  return 0;
}
