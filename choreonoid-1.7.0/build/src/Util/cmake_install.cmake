# Install script for directory: /home/bato/cit/lab/choreonoid-1.7.0/src/Util

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/choreonoid-1.7/src/Util" TYPE FILE FILES "/home/bato/cit/lab/choreonoid-1.7.0/build/src/Util/Config.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/locale/ja/LC_MESSAGES" TYPE FILE FILES "/home/bato/cit/lab/choreonoid-1.7.0/build/share/locale/ja/LC_MESSAGES/CnoidUtil-1.7.mo")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Dd][Ee][Bb][Uu][Gg]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidUtil.so.1.7" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidUtil.so.1.7")
      file(RPATH_CHECK
           FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidUtil.so.1.7"
           RPATH "$ORIGIN")
    endif()
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/bato/cit/lab/choreonoid-1.7.0/build/lib/libCnoidUtil.so.1.7")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidUtil.so.1.7" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidUtil.so.1.7")
      file(RPATH_CHANGE
           FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidUtil.so.1.7"
           OLD_RPATH "/home/bato/cit/lab/choreonoid-1.7.0/build/lib:/home/bato/cit/lab/choreonoid-1.7.0/build/lib/choreonoid-1.7:/usr/local/lib:"
           NEW_RPATH "$ORIGIN")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidUtil.so.1.7")
      endif()
    endif()
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Dd][Ee][Bb][Uu][Gg]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Dd][Ee][Bb][Uu][Gg]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidUtil.so" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidUtil.so")
      file(RPATH_CHECK
           FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidUtil.so"
           RPATH "$ORIGIN")
    endif()
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/bato/cit/lab/choreonoid-1.7.0/build/lib/libCnoidUtil.so")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidUtil.so" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidUtil.so")
      file(RPATH_CHANGE
           FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidUtil.so"
           OLD_RPATH "/home/bato/cit/lab/choreonoid-1.7.0/build/lib:/home/bato/cit/lab/choreonoid-1.7.0/build/lib/choreonoid-1.7:/usr/local/lib:"
           NEW_RPATH "$ORIGIN")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidUtil.so")
      endif()
    endif()
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Dd][Ee][Bb][Uu][Gg]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/choreonoid-1.7/cnoid/src/Util" TYPE FILE FILES
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/Referenced.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/EasyScanner.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/GaussianFilter.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/UniformCubicBSpline.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/IdPair.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/Array2D.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/Deque2D.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/PolymorphicReferencedArray.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/PolymorphicPointerArray.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/PolymorphicFunctionSet.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/MultiSE3Seq.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/MultiSE3MatrixSeq.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/MultiSeq.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/MultiValueSeq.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/MultiVector3Seq.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/NullOut.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/PlainSeqFileLoader.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/RangeLimiter.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/Seq.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/AbstractSeq.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/Timeval.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/TimeMeasure.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/Sleep.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/Vector3Seq.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/FileUtil.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/ExecutablePath.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/ParametricPathProcessor.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/UTF8.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/BoundingBox.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/SceneGraph.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/SceneDrawables.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/SceneCameras.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/SceneLights.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/SceneEffects.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/SceneRenderer.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/SceneUtil.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/AbstractSceneLoader.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/SceneLoader.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/MeshGenerator.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/MeshFilter.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/MeshExtractor.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/SceneMarkers.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/CoordinateAxesOverlay.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/SceneProvider.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/Collision.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/CollisionDetector.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/Triangulator.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/PolygonMeshTriangulator.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/PolyhedralRegion.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/Image.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/ImageIO.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/ImageConverter.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/ImageProvider.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/PointSetUtil.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/YAMLSceneLoader.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/YAMLSceneReader.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/VRML.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/VRMLParser.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/VRMLWriter.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/VRMLToSGConverter.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/Parser.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/STLSceneLoader.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/ValueTree.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/ValueTreeUtil.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/YAMLReader.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/YAMLWriter.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/EigenTypes.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/EigenUtil.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/EigenArchive.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/Signal.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/ConnectionSet.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/GettextUtil.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/Selection.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/DataMap.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/JoystickInterface.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/Joystick.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/ExtJoystick.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/SharedJoystick.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/Task.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/AbstractTaskSequencer.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/Exception.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/exportdecl.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/CnoidUtil.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Util/ThreadPool.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/Util/pybind11/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/Util/lua/cmake_install.cmake")

endif()

