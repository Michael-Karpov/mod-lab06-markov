// Copyright 2022 UNN-IASR
#pragma once
#include <deque>
#include <map>
#include <string>
#include <vector>

class Gen {
public:
 std::vector<std::string> words;
 typedef std::deque<std::string> prefix;
 std::map<prefix, std::vector<std::string> > statetab;  // prefix-suffix
 int NPREF;  // kol-vo slov s prefixe
 int MAXGEN;  // max kol-vo texta
 Gen(std::string file);
 std::string generate();
};
