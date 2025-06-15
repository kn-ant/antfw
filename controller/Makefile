CROSS_COMPILE=aarch64-linux-gnu-
CC=$(CROSS_COMPILE)gcc-12
CXX=$(CROSS_COMPILE)g++-12

APP=watcher.app

SRCDIR=src
OBJDIR=obj
INCDIR=inc

COMMONFLAGS=-g -Wall -Werror
CFLAGS=$(COMMONFLAGS) -std=c11
CXXFLAGS=$(COMMONFLAGS) -std=c++11
INCS=-I$(INCDIR)
MACROS=-DLOG_LEVEL=LOG_LEVEL_DBG

# Add source files here
CSRCS=
CPPSRCS=main.cpp

COBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(CSRCS))
CXXOBJS=$(patsubst %.cpp, $(OBJDIR)/%.o, $(CPPSRCS))


all: prebuild $(APP)
	echo "Building Done"

prebuild:
	mkdir -p $(OBJDIR)

deploy:
	echo "Deploying \"$(APP)\""
	scp $(APP) kntest@192.168.10.123:/home/kntest/deploy

clean:
	rm -rf $(OBJDIR) $(APP)
	echo "Cleaning Done"

$(APP): $(COBJS) $(CXXOBJS)
	echo "Building application \"$(APP)\""
	$(CXX) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	echo "Building $^ -> $@"
	$(CC) -c $(CFLAGS) $(INCS) $(MACROS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	echo "Building $^ -> $@"
	$(CXX) -c $(CXXFLAGS) $(INCS) $(MACROS) $^ -o $@

.SILENT:
.PHONY: prebuild clean deploy all