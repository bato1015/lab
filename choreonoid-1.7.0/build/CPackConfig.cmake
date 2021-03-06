# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "/home/bato/cit/lab/choreonoid-1.7.0;/home/bato/cit/lab/choreonoid-1.7.0/build")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6, libgcc1, libstdc++6, libpng12-0, libjpeg62, libyaml-0-2, zlib1g, libboost-filesystem1.42.0, libboost-date-time1.42.0, libboost-program-options1.42.0, libboost-python1.42.0, libboost-system1.42.0, libqtcore4, libqtgui4, libqt4-test, libqt4-opengl, libstdc++-dev, libboost-dev, libboost-program-options-dev, libboost-python-dev, libqt4-dev, libqt4-opengl-dev")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Shin'ichiro Nakaoka")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/home/bato/.local/lib/python3.6/site-packages/cmake/data/share/cmake-3.21/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "Choreonoid built using CMake")
set(CPACK_GENERATOR "DEB")
set(CPACK_INSTALL_CMAKE_PROJECTS "/home/bato/cit/lab/choreonoid-1.7.0/build;Choreonoid;ALL;/")
set(CPACK_INSTALL_PREFIX "/usr/local")
set(CPACK_MODULE_PATH "")
set(CPACK_NSIS_DISPLAY_NAME "Choreonoid 1.7")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "Choreonoid 1.7")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OUTPUT_CONFIG_FILE "/home/bato/cit/lab/choreonoid-1.7.0/build/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/home/bato/.local/lib/python3.6/site-packages/cmake/data/share/cmake-3.21/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Choreonoid")
set(CPACK_PACKAGE_FILE_NAME "choreonoid_1.7.0_i386")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "Choreonoid 1.7")
set(CPACK_PACKAGE_INSTALL_REGISTORY_KEY "Choreonoid 1.7")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "Choreonoid 1.7")
set(CPACK_PACKAGE_NAME "Choreonoid")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Shin'ichiro Nakaoka, AIST")
set(CPACK_PACKAGE_VERSION "1.7.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "7")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_RESOURCE_FILE_LICENSE "/home/bato/cit/lab/choreonoid-1.7.0/LICENSE")
set(CPACK_RESOURCE_FILE_README "/home/bato/.local/lib/python3.6/site-packages/cmake/data/share/cmake-3.21/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "/home/bato/.local/lib/python3.6/site-packages/cmake/data/share/cmake-3.21/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "TBZ2;TGZ;TXZ;TZ")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/home/bato/cit/lab/choreonoid-1.7.0/build/CPackSourceConfig.cmake")
set(CPACK_SOURCE_RPM "OFF")
set(CPACK_SOURCE_TBZ2 "ON")
set(CPACK_SOURCE_TGZ "ON")
set(CPACK_SOURCE_TXZ "ON")
set(CPACK_SOURCE_TZ "ON")
set(CPACK_SOURCE_ZIP "OFF")
set(CPACK_SYSTEM_NAME "Linux")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "Linux")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/home/bato/cit/lab/choreonoid-1.7.0/build/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
