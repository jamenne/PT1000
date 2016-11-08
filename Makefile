CXX		= g++
CXXFLAGS	= -O2 -Wall 
LDFLAGS		= -lgpib
SRCFILES	= PT1000Control.cpp PT1000ControlMain.cpp
OBJFILES    = PT1000Control.o PT1000ControlMain.o ../MultiMeter/MultiMeter.o ../gpib/gpib.o ../LogFileDev/LogDev.o

PT1000Control:		$(OBJFILES)
		$(CXX) $(OBJFILES) $(LDFLAGS) -o $@

clean:
		rm -f $(OBJFILES) PT1000Control 

PT1000Control.o:	PT1000Control.cpp PT1000Control.h

PT1000ControlMain.o: PT1000ControlMain.cpp PT1000Control.h