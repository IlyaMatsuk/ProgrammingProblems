#include <map>
#include <iostream>
#include <functional>
#include <string>
#include <list>
#include "../utils/time_meter.h"
#include "../utils/test.h"

int FindUniqChar_Readable(const std::string& s) {
  std::map<char, size_t> s_map;
  for(size_t i = 0; i < s.size(); ++i){
    auto search = s_map.find(s[i]);
    if(search != s_map.end())
      search->second++;
    else
      s_map.insert({s[i], 1});
  }

  for(size_t i = 0; i < s_map.size(); ++i)
    if(s_map[s[i]] == 1)
      return i;
  return -1;
}

int FindUniqChar_Faster(const std::string& s) {
  auto eq_counter = 0;
  bool is_found_first_uniq = false;
  size_t i = 0;
  for(i = 1; i < s.size(); ++i){
    if(s[i] == s[i-1]){
      is_found_first_uniq = false;
      eq_counter = 0;
    } else {
      eq_counter++;
      is_found_first_uniq = true;
    }

    if(eq_counter == 2 && is_found_first_uniq)
      return i - 1;
  }

  if(eq_counter == 2 && is_found_first_uniq)
    return i - 1;
  return -1;
}

int main() {
  std::list<std::string> data_list {"aabbcdee", "aabbccc", "aaaaabbbbsssjjjjjjjjfffllliiitttnnnffggeeelllqqqqpppeeennndddvvvcccsssrrrtttqqqyyyrrriiirrraaaaabbbbsssjjjjjjjjfffllliiitttnnnffggeeelllqqqqpppeeennndddvvvcccsssrrrtttqqqyyyrrriiirrraaaaabbbbsssjjjjjjjjfffllliiitttnnnffggeeelllqqqqpppeeennndddvvvcccsssrrrtttqqqyyyrrriiirrraaaaabbbbsssjjjjjjjjfffllliiitttnnnffggeeelllqqqqpppeeennndddvvvcccsssrrrtttqqqyyyrrriiirrraaaaabbbbsssjjjjjjjjfffllliiitttnnnffggeeelllqqqqpppeeennndddvvvcccsssrrrtttqqqyyyrrriiirrraaaaabbbbsssjjjjjjjjfffllliiitttnnnffggeeelllqqqqpppeeennndddvvvcccsssrrrtttqqqyyyrrriiirrrtffftfffhffffuuee"};
  std::cout << "FindUniqChar_Readable: " << Test<int (const std::string&), std::list<std::string>>(FindUniqChar_Readable, data_list) << std::endl;
  std::cout << "FindUniqChar_Faster: " << Test<int (const std::string&), std::list<std::string>>(FindUniqChar_Faster, data_list) << std::endl;
  return 0;
}