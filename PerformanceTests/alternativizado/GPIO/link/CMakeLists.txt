CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(iosharp)

SET(SysLib IOSharp.c IOSharp.h)
##################################################
#LINK LIBRARIES
##################################################
ADD_LIBRARY(IOSharp ${SysLib})

#SET_TARGET_PROPERTIES(System PROPERTIES LINKER_LANGUAGE CXX)