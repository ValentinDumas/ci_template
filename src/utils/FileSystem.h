//
// Created by Spark on 29/04/2019.
//

#ifndef CI_TEMPLATE_FILESYSTEM_H
#define CI_TEMPLATE_FILESYSTEM_H

#include <string>

#include <cppfs/fs.h>
#include <cppfs/FilePath.h>
#include <cppfs/FileHandle.h>
#include <cppfs/Tree.h>

namespace utils {
    namespace filesystem {
        std::string get_current_path();

        void list_directory_entries(const std::string &path);

        void list_recursive_directory_entries(const std::string &path);

        cppfs::FileHandle get_entry(const std::string &path);
    }
}

#endif //CI_TEMPLATE_FILESYSTEM_H
