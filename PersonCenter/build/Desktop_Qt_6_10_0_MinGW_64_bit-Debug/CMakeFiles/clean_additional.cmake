# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PersonCenter_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PersonCenter_autogen.dir\\ParseCache.txt"
  "PersonCenter_autogen"
  )
endif()
