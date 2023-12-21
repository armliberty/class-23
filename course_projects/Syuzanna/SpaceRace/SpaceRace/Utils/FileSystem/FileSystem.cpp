#include "FileSystem.hpp"

void FileSystem::save_name(std::string array)
{
    std::fstream file;
    file.open("registration_list.txt", std::ios::in);
    if (!file)
    {
        return;
    }
    else
    {
        for (int i = 0; i < (int)array.size(); ++i)
        {
            file << array[i] << std::endl;
        }
        file.close();
    }
}

void FileSystem::save_points(int point)
{
    std::fstream file;
    file.open("registration_list.txt", std::ios::app);
    if (!file)
    {
        return;
    }
    else
    {
        file << point << std::endl;
    }
    file.close();
}

std::string FileSystem::read_registration()
{
    std::string registration;
    std::fstream file;
    file.open("registration_list.txt", std::ios::out);
    if (!file)
    {
        return "";
    }
    else
    {
        for (int i = 0; i < (int)registration.size(); ++i)
        {
            file >> registration[i];
        }
        file.close();
    }

    return registration;
}

const char *FileSystem::convert_int_to_char(int integer)
{
    std::string temp_str = std::__cxx11::to_string(integer);
    char const *integers_array = temp_str.c_str();
    return integers_array;
}