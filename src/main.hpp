#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream> 
#include <algorithm>
#include <cstring>

#define INDEXLIMIT 140
#define INDEXNAME "AppListIndex.txt"
#define INDEXSYMBOL '='
#define VERSION "1.1.5"

void deleteAppList();
void addToAppList(const unsigned short InitialIndex);

std::fstream IndexFile;