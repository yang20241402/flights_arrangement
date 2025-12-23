# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PassengerLib_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PassengerLib_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\PersonCenter_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PersonCenter_autogen.dir\\ParseCache.txt"
  "PassengerLib_autogen"
  "PersonCenter_autogen"
  )
endif()
