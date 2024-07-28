
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>

#include <windows.h>
#include <shlobj.h>

// 批量命名文件
// 按顺序
void NameFiles(std::string);

// 选择文件夹
bool getPath(std::string &);
