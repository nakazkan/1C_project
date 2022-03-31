#include <cassert>
#include <fstream>
#include <iostream>
#include "suff_automaton.h"

void FindOccurance() {
  std::string path;
  std::cout << "Enter the path to the file:\n";
  getline(std::cin, path);
  std::ifstream file;
  file.open(path);

  assert(("File can not be opened", file.is_open()));
  std::string str;
  std::string text;
  while (getline(file, str)) {
    str.push_back(' ');
    text += str;
  }
  file.close();

  SuffAutomaton AS = SuffAutomaton();
  AS.Insert(text);

  int requests_cnt;
  std::cin >> requests_cnt;
  std::string request;
  getline(std::cin, request);

  for (int i = 0; i < requests_cnt; ++i) {
    getline(std::cin, request);
    size_t answer = AS.Find(request);
    if (answer) {
      std::cout << "First occurrence in " << answer << " position\n";
    } else {
      std::cout << "No occurrences in text\n";
    };
  }
}