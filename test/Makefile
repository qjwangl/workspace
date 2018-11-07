.SUFFIXES: .idl .cpp .o

PROGRAM = getopt

OBJECTS = hello.o getopt.o

SRC_HOME = $(HOME)/source

COM     = g++

INCPATH = -I$(HOME)/linux4.9.88/include -I$(HOME)/source/getopt 

LDPATH = -L$(HOME)/linux4.9.88/lib

DEBUG = -g

$(PROGRAM): $(OBJECTS)
	$(COM) -g -o $@ $(OBJECTS) $(LDPATH) $(LIB)
$(OBJECTS): %.o:%.cpp
	$(COM) -g -c $< -o $@ $(INCPATH)

# optional part


RM      = rm -f

clean:
		$(RM) $(PROGRAM) $(OBJECTS)

cleano:
		$(RM) $(OBJECTS)

cleanp:
		$(RM) $(PROGRAM)
install:
		@echo   cp -pf $(PROGRAM) $(HOME)/bin
		@       cp -pf $(PROGRAM) $(HOME)/bin
