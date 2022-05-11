// Copyright 2022 UNN-IASR
#include <fstream>
#include <iostream>
#include "textgen.h"

int main() {
  Gen g("in.txt");
  string output = g.generate();
  ofstream fout;
  fout.open("out.txt");
  fout << output;
  fout.close();
  return 1;
}
