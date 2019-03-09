// This is free and unencumbered software released into the public domain.

// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.

// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all present and future rights to this
// software under copyright law.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

// For more information, please refer to <http://unlicense.org>

#pragma once
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::greater;
using std::max;
using std::min;
using std::setprecision;

struct BoolName : std::numpunct<char> {
  std::string t, f;
  BoolName (std::string t = "Yes", std::string f = "No") : t(t), f(f) {}
  std::string do_truename() const {return t;}
  std::string do_falsename() const {return f;}
};

struct Initializer {
  Initializer() {
    cin.tie(0);
    std::ios::sync_with_stdio(0);
    cout << std::fixed << setprecision(15) << std::boolalpha;
    cout.imbue(std::locale(cout.getloc(), new BoolName));
  }
} initializer;

void set_bool_name(std::string t, std::string f) {
  cout.imbue(std::locale(cout.getloc(), new BoolName(t, f)));
}

template<typename T> bool chmin(T& a, T b) {return a > b ? a = b, true : false;}

template<typename T> bool chmax(T& a, T b) {return a < b ? a = b, true : false;}
