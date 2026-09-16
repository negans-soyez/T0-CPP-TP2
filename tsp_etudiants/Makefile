# Variables
CXX       = g++
CXXFLAGS  = -O3 -Wall -g -Wpedantic -Wshadow
LDFLAGS   = -L/usr/lib
INC_DIR   = -Iinclude
LIBS      = -lm
SRC_DIR   = src
OBJ_DIR   = obj
FILES_EXT = cpp
TARGET    = main.exe
SRC       = $(notdir $(wildcard $(SRC_DIR)/*.$(FILES_EXT)))
OBJ       = $(SRC:%.$(FILES_EXT)=$(OBJ_DIR)/%.o)

# Rules
all: depend $(OBJ) $(TARGET)

depend:
ifeq ("$(wildcard $(OBJ_DIR))","")
	@mkdir $(OBJ_DIR)
endif
	@echo -n "+ Generate dependencies : "
ifneq ($(strip $(SRC)),)
	@$(CXX) $(INC_DIR) -MM $(SRC:%=$(SRC_DIR)/%) \
	| sed -e 's:^[^ ]:$(OBJ_DIR)/&:' > Makefile.depend
endif
	@echo "OK"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(FILES_EXT)
	@echo -n "+ Compiling $(notdir $@) : "
	@$(CXX) $(CXXFLAGS) $(LDFLAGS) $(INC_DIR) -c $< -o $@
	@echo "OK"

$(TARGET): $(OBJ)
	@echo -n "+ Building $@ : "
	@$(CXX) $(CXXFLAGS) $(INC_DIR) $^ -o $@ $(LDFLAGS) $(LIBS)
	@echo "OK"

clean:
	@echo -n "+ Deleting objects : "
	@\rm -rf $(OBJ_DIR) $(TARGET)
	@echo "OK"

include Makefile.depend

.PHONY: all depend clean
