# Install script for directory: /home/bato/cit/lab/choreonoid-1.7.0/src/Body

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/locale/ja/LC_MESSAGES" TYPE FILE FILES "/home/bato/cit/lab/choreonoid-1.7.0/build/share/locale/ja/LC_MESSAGES/CnoidBody-1.7.mo")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Dd][Ee][Bb][Uu][Gg]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBody.so.1.7" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBody.so.1.7")
      file(RPATH_CHECK
           FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBody.so.1.7"
           RPATH "$ORIGIN")
    endif()
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/bato/cit/lab/choreonoid-1.7.0/build/lib/libCnoidBody.so.1.7")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBody.so.1.7" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBody.so.1.7")
      file(RPATH_CHANGE
           FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBody.so.1.7"
           OLD_RPATH "/home/bato/cit/lab/choreonoid-1.7.0/build/lib:/home/bato/cit/lab/choreonoid-1.7.0/build/lib/choreonoid-1.7:/usr/local/lib:"
           NEW_RPATH "$ORIGIN")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBody.so.1.7")
      endif()
    endif()
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Dd][Ee][Bb][Uu][Gg]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Dd][Ee][Bb][Uu][Gg]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBody.so" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBody.so")
      file(RPATH_CHECK
           FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBody.so"
           RPATH "$ORIGIN")
    endif()
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/bato/cit/lab/choreonoid-1.7.0/build/lib/libCnoidBody.so")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBody.so" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBody.so")
      file(RPATH_CHANGE
           FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBody.so"
           OLD_RPATH "/home/bato/cit/lab/choreonoid-1.7.0/build/lib:/home/bato/cit/lab/choreonoid-1.7.0/build/lib/choreonoid-1.7:/usr/local/lib:"
           NEW_RPATH "$ORIGIN")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBody.so")
      endif()
    endif()
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Dd][Ee][Bb][Uu][Gg]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/choreonoid-1.7/cnoid/src/Body" TYPE FILE FILES
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/Body.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/VRMLBody.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/BodyCustomizerInterface.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/AbstractBodyLoader.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/VRMLBodyLoader.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/BodyLoader.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/ZMPSeq.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/Link.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/LinkTraverse.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/LinkPath.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/JointPath.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/LinkGroup.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/Material.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/ContactMaterial.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/MaterialTable.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/BodyCollisionDetector.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/BodyCollisionDetectorUtil.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/MultiDeviceStateSeq.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/Device.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/DeviceList.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/ForceSensor.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/RateGyroSensor.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/AccelerationSensor.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/BasicSensorSimulationHelper.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/Camera.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/RangeCamera.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/RangeSensor.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/Light.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/PointLight.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/SpotLight.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/MarkerDevice.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/SceneBody.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/SceneDevice.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/SceneCollision.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/InverseKinematics.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/CompositeIK.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/PinDragIK.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/LeggedBodyHelper.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/PenetrationBlocker.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/ForwardDynamics.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/ForwardDynamicsABM.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/ForwardDynamicsCBM.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/DyBody.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/DyWorld.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/InverseDynamics.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/Jacobian.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/MassMatrix.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/ConstraintForceSolver.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/PoseProvider.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/BodyMotion.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/BodyMotionPoseProvider.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/PoseProviderToBodyMotionConverter.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/BodyMotionUtil.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/BodyState.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/CollisionLinkPair.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/ExtraJoint.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/ControllerIO.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/SimpleController.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/exportdecl.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Body/CnoidBody.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/choreonoid-1.7/simplecontroller" TYPE DIRECTORY FILES "/home/bato/cit/lab/choreonoid-1.7.0/build/lib/choreonoid-1.7/simplecontroller" FILES_MATCHING REGEX "/[^/]*$" EXCLUDE)
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/Body/pybind11/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/Body/lua/cmake_install.cmake")

endif()

