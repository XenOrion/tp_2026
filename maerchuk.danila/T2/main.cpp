#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>
#include "data_struct.hpp"

int main()
{
  using nspace::DataStruct;
  std::vector< DataStruct > data;

  // Попытка чтения
  while (!std::cin.eof())
  {
    if (!(std::cin >> std::ws)) break; // Пропуск пробелов

    DataStruct temp;
    if (std::cin >> temp)
    {
      data.push_back(temp);
    }
    else
    {
      if (std::cin.eof()) break;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }

  // Сортировка [cite: 6, 10]
  std::sort(data.begin(), data.end());

  if (!data.empty())
  {
    std::copy(
      data.begin(),
      data.end(),
      std::ostream_iterator< DataStruct >(std::cout, "\n")
    );
  }

  return 0;
}
