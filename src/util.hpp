#include <iostream>
#include <sstream>
#include <vector>

template <typename Iter>
std::string join(Iter begin, Iter end, const std::string &s);

template <typename T>
std::ostream &operator<<(std::ostream &ostream, std::vector<T> vec);

///

template <typename Iter>
std::string join(Iter begin, Iter end, const std::string &s) {
  std::stringstream ss;
  while (begin != end) {
    ss << *begin;
    ++begin;
    if (begin != end) {
      ss << s;
    }
  }
  return ss.str();
}

template <typename T>
std::ostream &operator<<(std::ostream &ostream, std::vector<T> vec) {
  ostream << "[" << join(vec.begin(), vec.end(), ", ") << "]";
  return ostream;
}
