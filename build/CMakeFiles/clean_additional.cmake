# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Obsidian_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Obsidian_autogen.dir/ParseCache.txt"
  "Obsidian_autogen"
  )
endif()
