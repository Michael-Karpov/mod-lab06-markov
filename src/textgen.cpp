// Copyright 2022 UNN-IASR
#include <time.h>
#include "textgen.h"
#include <iostream>
#include <fstream>
#include <locale>
#include <random>
#include <ctime>

Gen::Gen(string file) {
  ifstream fin;
  fin.open(file);
  vector<string> words;
  string word;
  while (!fin.eof()) {
    fin >> word;
    words.push_back(word);
 }
  fin.close();
  for (int i = 0; i < words.size() - NPREF + 1; i++) {
    prefix prfx;
    for (int j = 0; j < NPREF; j++)
      prfx.push_back(words.at(i + j));
    if (i == words.size() - NPREF)
      statetab[prfx].push_back("<LP>");
    else
      statetab[prfx].push_back(words.at(i + NPREF));
  }
}

string Gen::generate() {
  srand(time(0));
  string output;
  deque<string> words;
  auto it = statetab.begin();
  advance(it, rand() % statetab.size());
  for (int i = 0; i < NPREF; i++)
    words.push_back(it->first.at(i));
  for (int i = 0; i < MAXGEN; i++) {
    prefix prfx;
    for (int i = 0; i < NPREF; i++)
      prfx.push_back(words.at(i));
    int random = rand() % statetab.find(prfx)->second.size();
    if (statetab.find(prfx)->second.at(random) == "<LP>") {
      break;
    }
    words.push_back(statetab.find(prfx)->second.at(random));
    output += words.at(0) + ' ';
    words.pop_front();
  }
  return output;
}
