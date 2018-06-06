#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <map>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::map;

void helpInfo() {
    string header = "myls [path|mask] [-l] [-h|--help] [--sort=U|S|t|X|D|s] [-r] [-R] [-F] \n\t List information about the FILEs (the current directory by default)\n";
    string body = "\n\
    -h, --help              display this help and exit\
    -l                      use a long listing format\
    -F                      append indicator (one of */=>@|) to entries\
    -r                      reverse order while sorting\
    -R                      list subdirectories recursively\
    --sort[=U|S|t|X|D|s]    sorting files by predicator\
    ";
    
    cout << header << body << endl;
}

vector<string> getFilesForPathes(const vector<string>& pathes) {
    vector<string> files;
    
    for (auto& path: pathes) {
        auto filepath = boost::filesystem::system_complete(path);
        //        boost::filesystem::path prev("..");
        if (boost::filesystem::exists(filepath)) {
            cout << "filepath: " << filepath << endl;
            for (boost::filesystem::path p : boost::filesystem::directory_iterator(filepath)) {
                files.push_back(p.filename().string());
            }
        }
        
    }
    
    return files;
}

vector<string> getFilesRecursively(const vector<string>& pathes) {
    cout << "showFilesRecursively" << endl;
    vector<string> files;
    for (auto& path : pathes) {
        boost::filesystem::recursive_directory_iterator dir(path), end;
        while(dir != end) {
            boost::filesystem::path new_path = dir->path();
            for (boost::filesystem::path p : boost::filesystem::directory_iterator(new_path)) {
                files.push_back(p.filename().string());
            }
            dir++;
        }
    }
    return files;
}

void showFiles(const vector<string>& files) {
    for (auto& file : files) {
        cout << file << endl;
    }
}

void showFilesWithDetails(const vector<string>& pathes) {
    cout << "Here will be file details" << endl;
}

void showFilesWithSpecialChars(const vector<string>& pathes) {
    cout << "showFilesSpecialChars" << endl;
}

void showFilesSorted(vector<string>& pathes, bool reversed) {
    cout << "Sorting function" << endl;
}

void readArgs(int argc, const char * argv[], vector<string>& pathes) {
    vector<string> args;
    for (int i = 1; i < argc; ++i) {
        string argument = argv[i];
        if ((boost::contains(argument, "-")) || (boost::contains(argument, "--"))) {
            args.push_back(argument);
        } else {
            pathes.push_back(argument);
        }
    }
    
    for (int i = 0; i < args.size(); ++i) {
        bool reversed = false;
        string argument = args[i];
        if ((argument == "-h") || (argument == "--help")) {
            helpInfo();
            exit(0);
        } else if (argument == "-l") {
            showFilesWithDetails(pathes);
        } else if (argument == "-F") {
            showFilesWithSpecialChars(pathes);
        } else if (argument == "-R") {
            getFilesRecursively(pathes);
        } else if (argument == "-r") {
            reversed = true;
        } else if (boost::contains(argument, "--sort") || argument == "-s") {
            showFilesSorted(pathes, reversed);
        } else if (argument == "-S") {
            
        } else if (argument == "-t") {
        
        } else if (argument == "-v") {
            
        } else if (argument == "-X") {
            
        } else if (boost::contains(argument, "-")) {
            cerr << "Error: there is no such option: " << argument << endl;
            exit(-1);
        }
    }
    auto files = getFilesForPathes(pathes);
    showFiles(files);
}

int main(int argc, const char * argv[]) {
    vector<string> pathes;
    readArgs(argc, argv, pathes);
    return 0;
}
