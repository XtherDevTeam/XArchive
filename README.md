# XArchive format

Packaging:

```c++
XArchive::ArchiveFormat Format;
Format.CompressDirectory("", DirectoryPath, OutputFilePath);
```

Extract:

```c++
std::filesystem::create_directories(OutputDirectory);
Format.DecompressToDirectory(ArchiveFilePath, OutputDirectory);
```

## Usage

Clone the repository, and add it to target with
```cmake
file(GLOB XARCHIVE_SRC_FILES
        path/to/xarchive/Exceptions/*.cpp
        path/to/xarchive/Sources/*.cpp)

add_executable(YourTarget blahblah ${XARCHIVE_SRC_FILES})
```

CLI Usage:
```
xar pack dirpath=path/to/dir out=path/to/xar_filepath
xar unpack in=path/to/xar out=path/to/dir
```