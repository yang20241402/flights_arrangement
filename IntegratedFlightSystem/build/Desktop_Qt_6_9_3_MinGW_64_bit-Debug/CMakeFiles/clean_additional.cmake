# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\IntegratedFlightSystem_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\IntegratedFlightSystem_autogen.dir\\ParseCache.txt"
  "IntegratedFlightSystem_autogen"
  )
endif()
