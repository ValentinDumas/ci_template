//#pragma once
//
//#include <string>
//#include <experimental/filesystem>
//

#include <cppfs/fs.h>
#include <cppfs/FilePath.h>
#include <cppfs/FileHandle.h>
#include <cppfs/Tree.h>

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

#define PATH_MAX_LENGTH 256

inline get_current_path()
{
	std::string path;

	GetCurrentDir(path, PATH_MAX_LENGTH);

	return path;
}

// get filename from path
inline std::string remove_extension(const std::string& filename) {
}

// check if directory exists from path (not recursive !) -> if yes, returns TRUE
inline bool FolderExists(const std::string& name, const std::string& path = "projects")
{
	// For files in path
	        // if path is matching the given filename

	return false;
}

// get all files paths from directory (recursively)

//inline std::vector<std::experimental::filesystem::path> GetFilePathsFromDirectory(const std::string &path)
//{
//	std::vector<std::experimental::filesystem::path> paths;
//
//	for (auto& item : std::experimental::filesystem::directory_iterator(std::experimental::filesystem::current_path().string() + "\\" + path))
//	{
//	    // bullshit (e.g. directory "dir.extdir" pass ...
//		if (item.path().has_filename() && item.path().has_extension())
//		{
//			paths.push_back(item.path());
//		}
//	}
//
//	return paths;
//}
//
//inline std::vector<std::experimental::filesystem::path> GetRecursiveFilePathsFromDirectory(const std::string &path)
//{
//	std::vector<std::experimental::filesystem::path> paths;
//
//	for (auto& item : std::experimental::filesystem::recursive_directory_iterator(std::experimental::filesystem::current_path().string() + "\\" + path))
//	{
//		if (std::experimental::filesystem::is_directory(item)) {}
//		else
//		{
//			paths.push_back(item.path());
//		}
//	}
//
//	return paths;
//}
//
//
//
////std::experimental::filesystem::directory_iterator* directory_entries(const std::string& path)
////{
////	return &std::experimental::filesystem::directory_iterator(path);
////}













// -----------------------------------------------------------------------


//inline std::string remove_extension(const std::string& filename) {
//	size_t lastdot = filename.find_last_of(".");
//	if (lastdot == std::string::npos) return filename;
//	return filename.substr(0, lastdot);
//}
//
//// TODO: Move in filesystem.h
//inline bool FolderExists(const std::string& name, const std::string& path = "projects")
//{
//	for (auto& item : std::experimental::filesystem::directory_iterator(path))
//	{
//		if (name == item.path().filename().string())
//		{
//			return true;
//		}
//	}
//
//	return false;
//}
//
//inline std::vector<std::experimental::filesystem::path> GetFilePathsFromDirectory(const std::string &path)
//{
//	std::vector<std::experimental::filesystem::path> paths;
//
//	for (auto& item : std::experimental::filesystem::directory_iterator(std::experimental::filesystem::current_path().string() + "\\" + path))
//	{
//		if (item.path().has_filename() && item.path().has_extension())
//		{
//			paths.push_back(item.path());
//		}
//	}
//
//	return paths;
//}
//
//inline std::vector<std::experimental::filesystem::path> GetRecursiveFilePathsFromDirectory(const std::string &path)
//{
//	std::vector<std::experimental::filesystem::path> paths;
//
//	for (auto& item : std::experimental::filesystem::recursive_directory_iterator(std::experimental::filesystem::current_path().string() + "\\" + path))
//	{
//		if (std::experimental::filesystem::is_directory(item)) {}
//		else
//		{
//			paths.push_back(item.path());
//		}
//	}
//
//	return paths;
//}
//
//
//
////std::experimental::filesystem::directory_iterator* directory_entries(const std::string& path)
////{
////	return &std::experimental::filesystem::directory_iterator(path);
////}