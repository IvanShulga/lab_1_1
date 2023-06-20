#pragma once

#include "includers.h"

#ifndef MASK_N
#define MASK_N

string reverse_word(const string& word);
bool match_mask(const string& word, const string& mask);
void filter_words(vector<string>& words, const string& mask);
vector<string> split_line(const string& line);
void mask_in_file_str(string filename, string outputFile);
void mask_in_file_ptr(char* fileName, char* outputFileName);
void longest_word_str(const string& infilename, const string& outfilename);
void longest_word_ptr(char* infilename, char* outfilename);

#endif
