#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Utility function to split string by delimiter
vector<string> split(const string &s, char delimiter) {
  vector<string> tokens;
  string token;
  istringstream tokenStream(s);
  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

// Utility function to trim whitespace
string trim(const string &str) {
  size_t first = str.find_first_not_of(' ');
  size_t last = str.find_last_not_of(' ');
  return str.substr(first, (last - first + 1));
}

// Utility function to read all lines from file
vector<string> readLines(const string &filename) {
  vector<string> lines;
  ifstream file(filename);
  string line;

  if (!file.is_open()) {
    cerr << "Could not open file: " << filename << endl;
    return lines;
  }

  while (getline(file, line)) {
    if (!line.empty()) { // Skip empty lines, remove if needed
      lines.push_back(line);
    }
  }
  return lines;
}

// Part 1 solution
int solvePart1(const vector<string> &input) {
  int ret = 0;
  auto digitCheck = [](const std::string &str, int &j) -> int {
    int original_j = j;
    int limit = j + 4;
    for (; j <= limit; j++) {
      if (!isdigit(str[j])) {
        break;
      }
    }
    // cout << "original_j" + to_string(original_j) << endl;
    // cout << "j" + to_string(j) << endl;
    // cout << "hello " + str.substr(original_j, j) << endl;
    //
    cout << "hello2 " + str.substr(original_j, j - original_j) << endl;
    return j != original_j ? stoi(str.substr(original_j, j - original_j)) : -1;
  };
  for (int i = 0; i < input.size(); i++) {
    string s = input[i];
    for (int j_one = 0; j_one < s.size(); j_one++) {
      int j = j_one;

      string first_compare = s.substr(j, 4);
      // cout << first_compare << endl;
      if (first_compare == "mul(") {
        j += 5;
        int first, second;
        first = digitCheck(s, j);
        if (first == -1)
          continue;

        if (s[j] != ',')
          continue;
        j++;
        second = digitCheck(s, j);

        // cout << "hello hello" << endl;
        if (second == -1)
          continue;

        // cout << "hello hello hello" << endl;
        if (s[j] == ')')
          ret += first * second;
      }
    }
  }
  return ret;
}

// Part 2 solution
int solvePart2(const vector<string> &input) { return 0; }

int main() {
  // Read input
  vector<string> input = readLines("input.txt");
  // Solve both parts
  cout << solvePart1(input) << endl;
  cout << solvePart2(input) << endl;

  return 0;
}
