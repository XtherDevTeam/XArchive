//
// Created by chou on 22-8-3.
//

#include "XArchiveFormatException.hpp"

#include <utility>

XArchiveFormatException::XArchiveFormatException(std::string str) : s(std::move(str)) {

}

const char *XArchiveFormatException::what() const noexcept {
    return s.c_str();
}
