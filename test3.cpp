#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class StringT3 {
public:
  string *MyStrings = new string[3];
  StringT3() = default;
  // Copy Constructor
  StringT3(const StringT3 &S2) {
    copy(S2);
  }
    
  void operator=(const StringT3 &S2) {
    copy(S2);
  }
    
  StringT3(string A, string B, string C) {
    MyStrings[0] = A; // NOLINT - not using move
    MyStrings[1] = B; // NOLINT - not using move
    MyStrings[2] = C; // NOLINT - not using move
    cout << "Created " << MyStrings[0] << MyStrings[1] << MyStrings[2] << endl;
  }
    
  void copy(const StringT3 &S2) {
    MyStrings[0] = S2.MyStrings[0]; // NOLINT - not using move
    MyStrings[1] = S2.MyStrings[1]; // NOLINT - not using move
    MyStrings[2] = S2.MyStrings[2]; // NOLINT - not using move
  }

  ~StringT3() {
    cout << "Deleting " << MyStrings[0] << MyStrings[1] << MyStrings[2] << endl;
    delete[] MyStrings;
  }
};

void test3() {
  StringT3 S1("a", "b", "c");
  StringT3 T1;
  T1 = S1;
  StringT3 U1(S1);
  U1.MyStrings[0] = "q";

  auto *S2ptr = new StringT3("w", "x", "y");
  StringT3 *T2ptr;
  T2ptr = S2ptr;

  vector<StringT3> V1;
  V1.push_back(S1);
  V1.push_back(T1);
  V1.push_back(U1);

  vector<StringT3 *> V2;
  V2.push_back(S2ptr);
  V2.push_back(T2ptr);

  delete S2ptr;
  cout << "test3 is done" << endl;
}
