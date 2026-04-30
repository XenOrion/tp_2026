#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP

#include <string>

namespace asik
{
  // формат ввода:
  // { "key1": 1.0d, "key2": "Let madness release you" }
  struct DataStruct
  {
    std::pair<long long, unsigned long long> key1;
    char key2;
    std::string key3;
    bool operator < (const DataStruct & other);
  };

  struct DelimiterIO
  {
    char exp;
  };

  struct DoubleIO
  {
    double& ref;
  };

  struct StringIO
  {
    std::string& ref;
  };

  struct LabelIO
  {
    std::string exp;
  };

  std::istream& operator>>(std::istream& in, DelimiterIO&& dest);
  std::istream& operator>>(std::istream& in, DoubleIO&& dest);
  std::istream& operator>>(std::istream& in, StringIO&& dest);
  std::istream& operator>>(std::istream& in, LabelIO&& dest);
  std::istream& operator>>(std::istream& in, DataStruct& dest);
  std::ostream& operator<<(std::ostream& out, const DataStruct& dest);
}

#endif
