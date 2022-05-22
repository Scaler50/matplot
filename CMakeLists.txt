cmake_minimum_required(VERSION 3.10)
project(matplot)
set(CMAKE_CXX_STANDARD 11)
#指定库路径
file(GLOB_RECURSE PYTHON2.7_LIB "/usr/lib/python2.7/config-x86_64-linux-gnu/*.so")
#指定头文件路径
set(PYTHON2.7_INLCUDE_DIRS "/usr/include/python2.7")

#添加头文件到工程
include_directories(include
        ${PYTHON2.7_INLCUDE_DIRS}
        )
#路径需要根据自己路径做调整
include_directories("./matplot_lib/")
# #这样配置可以使得matplotlib.h中找到python.h文件，通常这样设置就可以。

add_executable(matplot demo.cpp)

#添加库文件到工程
target_link_libraries(matplot
  ${PYTHON2.7_LIB}
)


