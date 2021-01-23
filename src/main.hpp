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
#define VERSION "1.1.3"

void AddToAppList(const unsigned short InitialIndex);
void DeleteAppList();

std::fstream IndexFile;