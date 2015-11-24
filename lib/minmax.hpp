#pragma once

template<typename T> bool chmin(T& a, T& b) {return a > b ? a = b, true : false;}

template<typename T> bool chmax(T& a, T& b) {return a < b ? a = b, true : false;}
