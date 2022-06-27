cmake_minimum_required(VERSION 2.8)

project(testas)
add_executable(testas anime.cpp)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

find_package(OpenCV REQUIRED) ##OpenCVのビルド環境の設定ファイルを読み込む

include_directories(
    ${OpenCV_INCLUDE_DIRS}
)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(testas ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${OpenCV_LIBRARIES} )