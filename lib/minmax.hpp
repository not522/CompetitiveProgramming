#pragma once
#include "template.hpp"

template<typename T, typename U> bool chmin(T& a, U b) {return a > b ? a = b, true : false;}

template<typename T, typename U> bool chmax(T& a, U b) {return a < b ? a = b, true : false;}
