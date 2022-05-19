# Install script for directory: /home/bato/cit/lab/choreonoid-1.7.0/src

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/Util/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/AISTCollisionDetector/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/AssimpSceneLoader/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/Body/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/Corba/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/OpenRTM/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/OpenHRPModelLoader/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/Base/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/AssimpPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/BodyPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/PoseSeqPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/BalancerPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/SceneEffectsPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/SceneEditPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/MediaPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/PythonPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/PythonSimScriptPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/LuaPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/ODEPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/AGXDynamicsPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/BulletPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/PhysXPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/SpringheadPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/RokiPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/MulticopterPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/CorbaPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/OpenRTMPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/TrafficControlPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/RobotAccessPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/Hrpsys31Plugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/OpenHRPPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/GrxUIPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/FCLPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/SDFPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/PCLPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/CompetitionPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/ScenarioPlugin/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/Choreonoid/cmake_install.cmake")

endif()

