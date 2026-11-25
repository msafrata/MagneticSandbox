# CMakeList.txt : CMake project for MagneticSandbox, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (MagneticSandbox "MagneticSandbox.cpp" "MagneticSandbox.h" "magnet/magnet.cpp" "magnet/magnet.h" "UI/viewport/viewport.cpp" "UI/viewport/viewport.h" "UI/viewport/camera.h" "UI/viewport/camera.cpp"   "UI/viewport/renderResources.cpp" "UI/viewport/renderResources.h" "magnet/field.h" "magnet/field.cpp" "UI/viewport/fieldView.h" "UI/viewport/fieldView.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MagneticSandbox PROPERTY CXX_STANDARD 20)
endif()


target_link_libraries(MagneticSandbox PRIVATE raylib)

# TODO: Add tests and install targets if needed.
