
#define OTHER_LIBS \
    p3egg:c pandaegg:m \
    p3pipeline:c p3event:c p3pstatclient:c panda:m \
    p3pandabase:c p3pnmimage:c p3mathutil:c p3linmath:c p3putil:c p3express:c \
    pandaexpress:m \
    p3interrogatedb:c p3prc:c p3dconfig:c p3dtoolconfig:m \
    p3dtoolutil:c p3dtoolbase:c p3dtool:m \
    $[if $[WANT_NATIVE_NET],p3nativenet:c] \
    $[if $[and $[HAVE_NET],$[WANT_NATIVE_NET]],p3net:c p3downloader:c]

#begin bin_target
  #define TARGET lwo2egg
  #define LOCAL_LIBS p3lwo p3lwoegg p3eggbase p3progbase

  #define SOURCES \
    lwoToEgg.cxx lwoToEgg.h

#end bin_target

#begin bin_target
  #define TARGET lwo-scan
  #define LOCAL_LIBS p3lwo p3progbase

  #define SOURCES \
    lwoScan.cxx lwoScan.h

#end bin_target
