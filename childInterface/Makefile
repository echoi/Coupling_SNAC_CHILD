CXX=g++-mp-4.4

CCFLAGS=-g -fPIC -I. -I../child/Code/ChildInterface
#LDFLAGS=-g -shared -lstdc++ -L/Users/eunseo/projects/SNAC_CHILD_Coupling/child-clinic-package_oct2011/bin -lchild
LDFLAGS=-g -dynamiclib -flat_namespace -undefined suppress -lstdc++ -L../child/bin -lchild

HEADERS=childInterface.h childInterface_Wrapper.h
OBJS=childInterface.o childInterface_Wrapper.o
#SHAREDOBJ=libchildInterfaceWrapper.so
SHAREDOBJ=libchildInterfaceWrapper.dylib

all: $(SHAREDOBJ)
default: all

%.o: %.cpp
	$(CXX) $(CCFLAGS) -c $<

$(SHAREDOBJ): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@
	mkdir ${SNAC_LIBDIR}; cp -f $@ ${SNAC_LIBDIR}
	mkdir ${SNAC_INCDIR}; cp -f ${HEADERS} ${SNAC_INCDIR}

clean:
	rm -f $(OBJS)
	rm -f $(SHAREDOBJ)
	rm -f ${SNAC_LIBDIR}/$(SHAREDOBJ)
