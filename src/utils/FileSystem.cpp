//
// Created by Spark on 01/05/2019.
//

#include "FileSystem.h"

#include <iostream>
#include <string>

#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef MSVC_PLATFORM
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

std::string utils::filesystem::get_current_path()
{
    char path[FILENAME_MAX];

    GetCurrentDir( path, FILENAME_MAX );

    printf("Current working (binary) dir: %s\n", path);

    return std::string(path);
}

cppfs::FileHandle utils::filesystem::get_entry(const std::string& path)
{
    cppfs::FileHandle entry = cppfs::fs::open(path);

    if(entry.isFile())
    {
        std::cout << "[info] entry is a file" << std::endl;
    }
    else if(entry.isDirectory())
    {
        std::cout << "[info] entry is a directory" << std::endl;
    }
    else if(!entry.exists())
    {
        std::cout << "[info] Entry does not exists (at path " << path << ")" << std::endl;
    }

    return entry; // Not sure about this behaviour ! # TODO: check what happens when cppfs::FileHandle is "null"
}

void utils::filesystem::list_directory_entries(const std::string & path)
{
    cppfs::FileHandle directory = cppfs::fs::open(path);

    for(auto r : directory.listFiles())
    {
        std::cout << "under parent dir  ==>  " << r.c_str() << std::endl;
    }
}

void utils::filesystem::list_recursive_directory_entries(const std::string &path)
{
    // ...
}

// list all files

