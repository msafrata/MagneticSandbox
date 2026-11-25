# CMakeList.txt : CMake project for MagneticSandbox, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (MagneticSandbox "MagneticSandbox.cpp" "MagneticSandbox.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MagneticSandbox PROPERTY CXX_STANDARD 20)
endif()


target_link_libraries(MagneticSandbox PRIVATE raylib)
# TODO: Add tests and install targets if needed.
