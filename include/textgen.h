// Copyright 2022 UNN-IASR
#pragma once
#include <string>
#include <deque>
#include <vector>
#include <map>

class genText {
 public:
    string data;
    string getText();

    std::vector<string> words;
    typedef std::deque<string> prefix;
    map<prefix, vector<string> > statetab;
    int NPREF;
    int MAXGEN;
    genText(string filename, int i1, int i2);
};
