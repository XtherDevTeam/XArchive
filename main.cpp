#include <iostream>
#include <map>
#include "Sources/ArchiveFormat.hpp"

std::map<std::string, std::string> Arguments;

void ParseArguments(int argc, const char **argv) {
    /* defaults */
    Arguments["PATH"] = (std::string) {".;"};
    for (int i = 1; i < argc; i++) {
        std::string Str = argv[i];
        size_t Equ = Str.find('=');
        if (Equ != std::string::npos) {
            std::string L = Str.substr(0, Equ);
            std::string R = Str.substr(Equ + 1);
            if (L[0] == '\'' || L[0] == '"') {
                L = L.substr(1, L.size() - 2);
            }
            if (R[0] == '\'' || R[0] == '"') {
                R = R.substr(1, R.size() - 2);
            }

            Arguments[L] = R;
        } else {
            Arguments[Str] = {};
        }
    }
}


int main(int argc, const char **argv) {
    ParseArguments(argc, argv);
    XArchive::ArchiveFormat Format;

    if (Arguments.count("pack")) {
        Format.CompressDirectory((std::filesystem::path) {""}, (std::filesystem::path) {Arguments["dir"]},
                                 (std::filesystem::path) {Arguments["out"]}, {});
        std::cout << "pack: success\n";
    } else if (Arguments.count("unpack")) {
        std::filesystem::create_directories(Arguments["out"]);
        Format.DecompressToDirectory(Arguments["in"], Arguments["out"]);
        std::cout << "unpack: success\n";
    } else {
        std::cout << "invalid param\n";
    }
    return 0;
}
