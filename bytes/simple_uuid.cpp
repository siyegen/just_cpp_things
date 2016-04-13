#include <iostream>
#include <ios>
#include <cstdio>
#include <string>


int main() {
  std::cout << "woo" << std::endl;

  const short buff_size = 16;
  unsigned char buffer[buff_size];
  char UUID[(buff_size*2)+5]; // 2 for each char, 1 for each -, and 1 for \0
  srand(time(NULL));

  std::cout << "sizeof buffer: " << sizeof(buffer) << std::endl;

  for(size_t i = 0; i < buff_size; i++){
    buffer[i] = rand();
  }

  int offset = 0;
  std::string fmt = "%02x";
  for (size_t i = 0; i < buff_size; i++) {
    if (i == 3) {
      fmt = "%02x-";
    } else if (i > 4 && i < 11) {
      fmt = "%02x";
      if (i%2!=0) fmt += "-";
    } else fmt = "%02x";
    offset += std::sprintf(UUID+offset, fmt.c_str(), buffer[i]);
  }
  std::string safe = std::string(UUID);
  std::cout << "uuid: " << UUID << std::endl;
  std::cout << "strsize: " << safe.size() << std::endl;

  return 0;
}
