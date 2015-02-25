cmake_minimum_required(VERSION 2.8)

project(atc3dgtracker)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include( cmake/FindLibUSB.cmake )

INCLUDE_DIRECTORIES(
	include
)

ADD_SUBDIRECTORY(include)
ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(src)

