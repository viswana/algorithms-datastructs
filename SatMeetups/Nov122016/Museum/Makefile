CXXFLAGS += -Wall -Wextra -g -std=c++11
TGT = Museum
all: Museum

TGT: Museum.cpp

clean:
	@rm -rf $(TGT)
	@rm -rf html latex

doc: doxyconfig
	doxygen doxyconfig

.PHONY: all clean doc
