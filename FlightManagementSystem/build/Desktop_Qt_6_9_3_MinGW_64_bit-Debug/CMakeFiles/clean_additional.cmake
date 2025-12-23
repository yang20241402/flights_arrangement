# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "modules\\authentication\\AuthenticationModule_autogen"
  "modules\\authentication\\CMakeFiles\\AuthenticationModule_autogen.dir\\AutogenUsed.txt"
  "modules\\authentication\\CMakeFiles\\AuthenticationModule_autogen.dir\\ParseCache.txt"
  "modules\\common\\CMakeFiles\\CommonModule_autogen.dir\\AutogenUsed.txt"
  "modules\\common\\CMakeFiles\\CommonModule_autogen.dir\\ParseCache.txt"
  "modules\\common\\CommonModule_autogen"
  "modules\\database\\CMakeFiles\\DatabaseModule_autogen.dir\\AutogenUsed.txt"
  "modules\\database\\CMakeFiles\\DatabaseModule_autogen.dir\\ParseCache.txt"
  "modules\\database\\DatabaseModule_autogen"
  "modules\\flight\\CMakeFiles\\FlightModule_autogen.dir\\AutogenUsed.txt"
  "modules\\flight\\CMakeFiles\\FlightModule_autogen.dir\\ParseCache.txt"
  "modules\\flight\\FlightModule_autogen"
  "modules\\user\\CMakeFiles\\UserModule_autogen.dir\\AutogenUsed.txt"
  "modules\\user\\CMakeFiles\\UserModule_autogen.dir\\ParseCache.txt"
  "modules\\user\\UserModule_autogen"
  "src\\CMakeFiles\\FlightManagementSystem_autogen.dir\\AutogenUsed.txt"
  "src\\CMakeFiles\\FlightManagementSystem_autogen.dir\\ParseCache.txt"
  "src\\FlightManagementSystem_autogen"
  )
endif()
