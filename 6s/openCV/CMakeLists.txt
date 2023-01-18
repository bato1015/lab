cmake_minimum_required(VERSION 3.10)
project(testas)
add_executable(testas depth_data.cpp)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
find_package(OpenCV REQUIRED) ##OpenCVのビルド環境の設定ファイルを読み込む
include_directories(
    ${OpenCV_INCLUDE_DIRS}
)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
target_link_libraries(testas ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${OpenCV_LIBRARIES} )
target_link_libraries(testas Eigen3::Eigen)