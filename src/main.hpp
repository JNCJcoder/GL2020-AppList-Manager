#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream> 
#include <algorithm>
#include <cstring>

#define INDEX_LIMIT 143
#define INDEX_NAME "AppListIndex.txt"
#define INDEX_SYMBOL '='
#define VERSION "1.1.8"

void deleteAppList();
void addToAppList(const unsigned short InitialIndex);

std::fstream IndexFile;