#ifndef FILE_SYSTEM_HPP
#define FILE_SYSTEM_HPP

#include <string>
#include <fstream>

namespace FileSystem
{
    void save_name(std::string array);
    void save_points(int point);
    std::string read_registration();
    const char *convert_int_to_char(int integer);
} // namespace FileSystem

#endif // FILE_SYSTEM_HPP