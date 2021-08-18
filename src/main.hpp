#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>

#define INDEX_LIMIT 143
#define INDEX_NAME "AppListIndex.txt"
#define INDEX_SYMBOL '='
#define INDEX_COM '#'
#define VERSION "2.0.0"

void deleteAppList();
void addToAppList(const unsigned short InitialIndex);

std::ifstream IndexFile;