#include <iostream>
#include "Sources/ArchiveFormat.hpp"

int main() {
    XArchive::ArchiveFormat Format;
//    std::filesystem::create_directories("./output");
//    Format.DecompressToDirectory("./test.xar", "./output");
    Format.CompressDirectory((std::filesystem::path) {""}, (std::filesystem::path) {"."},
                             (std::filesystem::path) {"./test.xar"}, {});
    return 0;
}
