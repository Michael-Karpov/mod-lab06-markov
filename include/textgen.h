// Copyright 2022 UNN-IASR
#pragma once
#include <deque>
#include <map>
#include <string>
#include <vector>
class Gen {
 private:
 typedef std::deque<std::string> prefix;
 std::map<prefix, vector<std::string>> statetab;
 int NPREF = 2;
 int MAXGEN = 1000;
 public:
 Gen(std::string file);
 std::string generate();
};
