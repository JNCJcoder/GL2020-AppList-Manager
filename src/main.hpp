#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream> 
#include <algorithm>
#include <cstring>

#define INDEXLIMIT 160
#define INDEXNAME "AppListIndex.txt"
#define INDEXSYMBOL '='
#define VERSION "1.0.1"

inline void AddToAppList();
inline void DeleteAppList();

std::fstream IndexFile;