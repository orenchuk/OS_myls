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

void showPathes(vector<string>& pathes) {
    if (pathes.empty()) {
        pathes.push_back(".");
    }
    for (auto& path : pathes) {
        cout << "path: " << path << endl;
    }
}

void showFiles(const vector<string>& pathes) {
    
}

void showFilesRecursively(const vector<string>& pathes) {
    
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

vector<string> getFilesForPathes(const vector<string>& pathes) {
    vector<string> files;
    
    return files;
}

void readArgs(int argc, const char * argv[], vector<string>& pathes) {
    for (int i = 1; i < argc; ++i) {
        string argument = argv[i];
        if ((argument == "-h") || (argument == "--help")) {
            // TO-DO: design the way that function will parse args and only after it will execute them
            helpInfo();
            exit(0);
        } else if (argument == "-l") {
            showFilesWithDetails(pathes);
        } else if (boost::contains(argument, "--sort")) {
            bool reversed = false;
            for (int j = i; j < argc; ++j) {
                string temp = argv[j];
                if (temp == "-r") {
                    reversed = true;
                }
            }
            showFilesSorted(pathes, reversed);
        } else if (argument == "-F") {
            showFilesWithSpecialChars(pathes);
        } else if (argument == "-R") {
            showFilesRecursively(pathes);
        } else if (boost::contains(argument, "-")) {
            cerr << "Error: there is no such option: " << argument << endl;
            exit(-1);
        } else {
            pathes.push_back(argument);
        }
    }
    
    showPathes(pathes);
}

int main(int argc, const char * argv[]) {
    vector<string> pathes;
    vector<string> files;
    readArgs(argc, argv, pathes);
    return 0;
}
