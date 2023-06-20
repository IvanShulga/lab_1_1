#pragma once
#include "includers.h"

#ifndef FILEFUNCTIONS
#define FILEFUNCTIONS

char* create_file_pointer();
void create_file_stream(string& fileNameStr);
void append_file_ptr(char* fileName);
void append_file_str(const string& fileName);
void read_file_ptr(char* fileNamePtr);
void read_file_str(const string& fileName);

#endif
