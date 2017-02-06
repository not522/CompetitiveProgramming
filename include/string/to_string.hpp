#pragma once
#include "template.hpp"

template<typename T> string to_string(const T& v) {
  string str;
  for (const auto& i : const_cast<T&>(v)) str += ' ' + to_string(i);
  return str.substr(min(1, int(str.size())));
}

template<> string to_string<string>(const string& v) {return v;}

#ifdef __MINGW32__

template<> string to_string<int>(const int& v) {
  stringstream ss;
  ss << v;
  return ss.str();
}

template<> string to_string<int64_t>(const int64_t& v) {
  stringstream ss;
  ss << v;
  return ss.str();
}

template<> string to_string<unsigned int>(const unsigned int& v) {
  stringstream ss;
  ss << v;
  return ss.str();
}

template<> string to_string<unsigned int64_t>(const unsigned int64_t& v) {
  stringstream ss;
  ss << v;
  return ss.str();
}

template<> string to_string<float>(const float& v) {
  stringstream ss;
  ss << v;
  return ss.str();
}

template<> string to_string<double>(const double& v) {
  stringstream ss;
  ss << v;
  return ss.str();
}

template<> string to_string<long double>(const long double& v) {
  stringstream ss;
  ss << v;
  return ss.str();
}

#endif
