cmake_minimum_required(VERSION 2.6)
project(NETMF-LINUX)

OPTION(NETMF-LINUX "Build the Marea-Zero library shared." ON)

if(NETMF-LINUX)
	SET(NETMF-LINUX_LIBRARY_TYPE SHARED)
endif(NETMF-LINUX)


add_library(netmf-linux ${NETMF-LINUX_LIBRARY_TYPE} netmf-linux.c)
install(TARGETS netmf-linux DESTINATION /usr/lib)
