#include <algorithm>
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
  // TODO: Implement part 1 solution
  int ret = 0;
  for (string line : input) {
    int num;
    vector<int> nums;
    stringstream ss(line);
    while (ss >> num) {
      nums.push_back(num);
    }
    if (nums[0] == nums[1])
      continue;

    bool increasing = nums[0] < nums[1];
    bool valid = true;
    for (int i = 0; i < nums.size() - 1; i++) {
      int diff = nums[i] - nums[i + 1];
      if (diff < 0 && !increasing || diff > 0 && increasing) {
        valid = false;
        continue;
      }
      if (abs(diff) > 3 || abs(diff) < 1) {
        valid = false;
        continue;
      }
    }

    if (valid)
      ret++;
  }
  return ret;
}

bool valid(const vector<int> &nums) {
  int ret = 0;
  bool increasing = nums[0] < nums[1];
  bool valid = true;
  for (int i = 0; i < nums.size() - 1; i++) {
    int diff = nums[i] - nums[i + 1];
    if (diff < 0 && !increasing || diff > 0 && increasing) {
      valid = false;
      continue;
    }
    if (abs(diff) > 3 || abs(diff) < 1) {
      valid = false;
      continue;
    }
  }

  return valid;
}

// Part 2 solution
int solvePart2(const vector<string> &input) {
  // TODO: Implement part 1 solution
  int ret = 0;
  for (string line : input) {
    int num;
    vector<int> nums;
    stringstream ss(line);
    while (ss >> num) {
      nums.push_back(num);
    }
    bool isOkay = false;
    auto consider = [&](int i) {
      vector<int> b = nums;
      b.erase(b.begin() + i);
      if (valid(b)) {
        isOkay = true;
      }
    };
    consider(0);

    for (int i = 0; i < nums.size() - 1; i++) {
      int diff = nums[i] - nums[i + 1];
      if (abs(diff) > 3 || abs(diff) < 1) {
        consider(i);
        consider(i + 1);
        break;
      }
      if (i + 2 < nums.size()) {
        int diff2 = nums[i + 1] - nums[i + 2];
        if ((diff > 0) != (diff2 > 0)) {
          consider(i);
          consider(i + 1);
          consider(i + 2);
          break;
        }
      }
    }
    if (isOkay)
      ret++;
  }

  return ret;
}

int main() {
  // Read input
  vector<string> input = readLines("input.txt");
  // Solve both parts
  cout << solvePart1(input) << endl;
  cout << solvePart2(input) << endl;

  return 0;
}
