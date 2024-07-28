
#include "FileMaster.hpp"

inline bool is_picture(std::string path)
{
    // 获取后缀名
    std::string suffix = path.substr(path.find_last_of('.') + 1);

    // 转换为小写
    std::transform(suffix.begin(), suffix.end(), suffix.begin(), ::tolower);

    // 判断是否为图片
    if (suffix == "jpg" || suffix == "jpeg" || suffix == "png" || suffix == "bmp" || suffix == "gif")
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 深度优先搜索
// 递归遍历文件夹
void DFS(std::string path, int *count)
{
    // 遍历该路径下的所有文件
    for (auto &p : std::filesystem::directory_iterator(path))
    {
        // 如果是文件夹
        if (std::filesystem::is_directory(p))
        {
            // 递归遍历
            DFS(p.path().string(), count);
        }
        // 如果是文件
        else if (std::filesystem::is_regular_file(p))
        {
            // 如果是图片
            if (is_picture(p.path().string()))
            {
                // 重命名
                // 高位用0补齐
                std::string new_name = std::to_string((*count)++);
                new_name.insert(new_name.begin(), 6 - new_name.size(), '0');
                new_name = path + "\\" + new_name + ".jpg";
                std::filesystem::rename(p.path(), new_name);

                std::cout << p.path().string() << " -> " << new_name << std::endl;
            }
        }
    }
}

void NameFiles(std::string path)
{
    std::cout << "Start naming files..." << std::endl;
    std::cout << "Path: " << path << std::endl;

    int count = 0;
    DFS(path, &count);

    std::cout << "Finish naming files." << std::endl;
}
