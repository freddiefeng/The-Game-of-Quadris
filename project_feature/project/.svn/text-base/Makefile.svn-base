OBJDIR=out
SRCDIR=src
BINDIR=bin
TSTDIR=test
INCDIR=inc
DEPDIR=deps
INCLUDE=-I${INCDIR}
CXX=g++
CXXFLAGS=-I${INCDIR} -g -Wall -c
SOURCES=${wildcard ${SRCDIR}/*.cc}
OBJECTS=${patsubst ${SRCDIR}/%.cc, ${OBJDIR}/%.o,${SOURCES}}
EXEC=walllessquadris
cmdTestBuild=${CXX} -g -Wall ${INCLUDE} $^ $(TSTDIR)/$@.cc -o $(BINDIR)/$@

$(EXEC) : $(OBJECTS)
	$(CXX) -g -Wall -lX11 $(INCLUDE) $(OBJDIR)/*.o -o $(EXEC)

${OBJDIR}/%.o : $(addprefix $(SRCDIR)/, %.cc)
	$(CXX) ${CXXFLAGS} $< -o $@

.PHONY : clean
clean:
	rm -f $(OBJDIR)/*.o  $(BINDIR)/* $(EXEC) > /dev/null  2>&1
