cmake_minimum_required(VERSION 2.8)
project( Chapter01 )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
<<<<<<< HEAD
add_executable( 2_mat.out 2_mat.cpp )
target_link_libraries( 2_mat.out ${OpenCV_LIBS} )
=======
add_executable( 1_hello_opencv.out 1_hello_opencv.cpp )
target_link_libraries( 1_hello_opencv.out ${OpenCV_LIBS} )
>>>>>>> c67f498326111ce49654c691e6bad0fd7b86e089
