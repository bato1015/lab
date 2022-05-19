# Install script for directory: /home/bato/cit/lab/choreonoid-1.7.0/src/Base

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/locale/ja/LC_MESSAGES" TYPE FILE FILES "/home/bato/cit/lab/choreonoid-1.7.0/build/share/locale/ja/LC_MESSAGES/CnoidBase-1.7.mo")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Dd][Ee][Bb][Uu][Gg]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBase.so.1.7" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBase.so.1.7")
      file(RPATH_CHECK
           FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBase.so.1.7"
           RPATH "$ORIGIN")
    endif()
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/bato/cit/lab/choreonoid-1.7.0/build/lib/libCnoidBase.so.1.7")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBase.so.1.7" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBase.so.1.7")
      file(RPATH_CHANGE
           FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBase.so.1.7"
           OLD_RPATH "/home/bato/cit/lab/choreonoid-1.7.0/build/lib:/home/bato/cit/lab/choreonoid-1.7.0/build/lib/choreonoid-1.7:/usr/local/lib:"
           NEW_RPATH "$ORIGIN")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBase.so.1.7")
      endif()
    endif()
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Dd][Ee][Bb][Uu][Gg]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Dd][Ee][Bb][Uu][Gg]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBase.so" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBase.so")
      file(RPATH_CHECK
           FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBase.so"
           RPATH "$ORIGIN")
    endif()
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/bato/cit/lab/choreonoid-1.7.0/build/lib/libCnoidBase.so")
    if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBase.so" AND
       NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBase.so")
      file(RPATH_CHANGE
           FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBase.so"
           OLD_RPATH "/home/bato/cit/lab/choreonoid-1.7.0/build/lib:/home/bato/cit/lab/choreonoid-1.7.0/build/lib/choreonoid-1.7:/usr/local/lib:"
           NEW_RPATH "$ORIGIN")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libCnoidBase.so")
      endif()
    endif()
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Dd][Ee][Bb][Uu][Gg]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/choreonoid-1.7/cnoid/src/Base" TYPE FILE FILES
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/App.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/MainWindow.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/Process.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/Action.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ActionGroup.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/SpinBox.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/FloatingNumberBox.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ScrollBar.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/Slider.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/Dial.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/Splitter.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/Buttons.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ButtonGroup.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/CheckBox.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/LineEdit.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ComboBox.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/Dialog.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/Timer.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/SocketNotifier.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ImageWidget.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/TreeView.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/TreeWidget.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ItemSelectionModel.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/MenuManager.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/Menu.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ToolBar.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/View.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ViewArea.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ViewManager.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/GraphWidget.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/GraphViewBase.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ExtensionManager.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/OptionManager.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ProjectManager.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/PluginManager.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/Plugin.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/MessageView.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ItemTreeView.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ItemList.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/Item.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/PutPropertyFunction.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/RootItem.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/FolderItem.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/SubProjectItem.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/AbstractSeqItem.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/MultiSeqItem.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/MultiValueSeqItem.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/MultiSE3SeqItem.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/MultiSE3MatrixSeqItem.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/Vector3SeqItem.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ExtCommandItem.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/AbstractTextItem.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ScriptItem.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ItemPath.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/TimeBar.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/TimeSyncItemEngine.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/GraphBar.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ItemManager.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/AppConfig.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/AppUtil.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/Archive.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ItemTreeArchiver.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/LazySignal.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/LazyCaller.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/SceneWidget.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/SceneWidgetEvent.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/SceneProjector.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/SceneDragProjector.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/SceneDragger.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/TranslationDragger.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/RotationDragger.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/PositionDragger.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/SceneBar.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/SceneWidgetEditable.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/InteractiveCameraTransform.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/RectRegionMarker.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/GLSceneRenderer.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/GL1SceneRenderer.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/GLSLSceneRenderer.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/SceneView.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/SceneItem.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/PointSetItem.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/MultiPointSetItem.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/TextEditView.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/GeneralSliderView.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/ImageView.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/JoystickCapture.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/TextEdit.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/TaskView.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/MessageLogItem.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/LightingItem.h"
    "/home/bato/cit/lab/choreonoid-1.7.0/src/Base/exportdecl.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/Base/pybind11/cmake_install.cmake")
  include("/home/bato/cit/lab/choreonoid-1.7.0/build/src/Base/lua/cmake_install.cmake")

endif()

