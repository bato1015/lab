# Install script for directory: /home/bato/cit/lab/choreonoid-1.7.0/src/PoseSeqPlugin/pybind11

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Dd][Ee][Bb][Uu][Gg]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/choreonoid-1.7/python/cnoid/PoseSeqPlugin.so" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/choreonoid-1.7/python/cnoid/PoseSeqPlugin.so")
      file(RPATH_CHECK
           FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/choreonoid-1.7/python/cnoid/PoseSeqPlugin.so"
           RPATH "$ORIGIN:$ORIGIN/../..:$ORIGIN/../../..")
    endif()
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/choreonoid-1.7/python/cnoid" TYPE SHARED_LIBRARY FILES "/home/bato/cit/lab/choreonoid-1.7.0/build/lib/choreonoid-1.7/python/cnoid/PoseSeqPlugin.so")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/choreonoid-1.7/python/cnoid/PoseSeqPlugin.so" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/choreonoid-1.7/python/cnoid/PoseSeqPlugin.so")
      file(RPATH_CHANGE
           FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/choreonoid-1.7/python/cnoid/PoseSeqPlugin.so"
           OLD_RPATH "/home/bato/cit/lab/choreonoid-1.7.0/build/lib:/home/bato/cit/lab/choreonoid-1.7.0/build/lib/choreonoid-1.7:/usr/local/lib:"
           NEW_RPATH "$ORIGIN:$ORIGIN/../..:$ORIGIN/../../..")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/choreonoid-1.7/python/cnoid/PoseSeqPlugin.so")
      endif()
    endif()
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Dd][Ee][Bb][Uu][Gg]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Dd][Ee][Bb][Uu][Gg]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Dd][Ee][Bb][Uu][Gg]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
endif()

