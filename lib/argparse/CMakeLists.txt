cmake_minimum_required(VERSION 3.9.2)

set(argparse_files
        argparse.cc)

add_library(argparse STATIC ${argparse_files})
