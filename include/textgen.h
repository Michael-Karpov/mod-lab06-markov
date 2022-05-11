// Copyright 2022 UNN-IASR
#pragma once
#include <deque>
#include <map>
#include <string>
#include <vector>

using namespace std;
class Gen {
private:
 typedef deque<string> prefix;
   map<prefix, vector<string>> statetab;
   int NPREF = 2;
   int MAXGEN = 1000;
public:
   Gen(string file);
   string generate();
};
