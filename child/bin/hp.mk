# HP compiler

CXX = cxx
#
# -O is necessary for -Wuninitialized to be on
# -Weffc++ -fmessage-length=0 gives useful but noisy warnings
WARNINGFLAGS =

# recent versions of Linux use new style casts in their headers
WARNINGFLAGS +=

# -march=i686: generates code for pentiumpro and later
# -march=pentium3: generates code for pentium III and later
ARCH := 
# optimise
#PROFILE = -pg
CFLAGS = $(WARNINGFLAGS) -g $(PROFILE) -02 $(ARCH) -c
LDFLAGS = $(WARNINGFLAGS) -g $(PROFILE) -O2 $(ARCH)
# no optimisation, build is faster
#CFLAGS = $(WARNINGFLAGS) -g $(ARCH) -c
#LDFLAGS = $(WARNINGFLAGS) -g $(ARCH)
LIBS = -lm -lfor -lFutil -lUfor

LDFLAGS += -o $@

OBJEXT = o
EXEEXT =
