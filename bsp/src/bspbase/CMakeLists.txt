# FIXME: This should be split up. Libraries that just need to read BSP files
# should not have to use all the BSP tool-related code.

set(P3BSPBASE_HEADERS
  common_config.h
  anorms.h
  blockmem.h
  bsp_boundingbox.h
  bspfile.h
  bsptools.h
  cmdlib.h
  cmdlinecfg.h
  filelib.h
  halton.h
  hlassert.h
  log.h
  mathlib.h
  mathtypes.h
  messages.h
  resourcelock.h
  scriplib.h
  threads.h
  TimeCounter.h
  win32fix.h
  winding.h
  mathlib/sse.h
  mathlib/ssemath.h
)

set(P3BSPBASE_SOURCES
  anorms.cpp
  blockmem.cpp
  bspfile.cpp
  bsptools.cpp
  cmdlib.cpp
  cmdlinecfg.cpp
  filelib.cpp
  files.cpp
  halton.cpp
  log.cpp
  mathlib.cpp
  messages.cpp
  resourcelock.cpp
  scriplib.cpp
  threads.cpp
  winding.cpp
  mathlib/powsse.cpp
  mathlib/sse.cpp
  mathlib/sseconst.cpp
)

composite_sources(p3bspbase P3BSPBASE_SOURCES)
add_library(p3bspbase STATIC ${P3BSPBASE_HEADERS} ${P3BSPBASE_SOURCES})
target_compile_definitions(p3bspbase PUBLIC NOMINMAX)
target_link_libraries(p3bspbase panda)
set_target_properties(p3bspbase PROPERTIES POSITION_INDEPENDENT_CODE ON)

# NOTE: This package is not installed.
