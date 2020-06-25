# - Config file for the inekf package
# It defines the following variables
#  inekf_INCLUDE_DIRS - include directories for inekf
#  inekf_LIBRARY_DIRS - directories for inekf library
 
# Compute paths
get_filename_component(inekf_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
set(inekf_INCLUDE_DIRS "/home/chenli/invariant-ekf/include;/usr/include;/usr/local/include/eigen3")
set(inekf_LIBRARY_DIRS "/home/chenli/invariant-ekf/lib")
set(inekf_LIBRARIES "inekf")

# This causes catkin_simple to link against these libraries
set(inekf_FOUND_CATKIN_PROJECT true)
