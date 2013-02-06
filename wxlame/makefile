APP_NAME		= wxlame
SRC_DIR			= ./src
PREFIX			= /usr
#DESTDIR			= /tmp/test

INSTALL_BIN_DIR 	= $(DESTDIR)$(PREFIX)/bin
INSTALL_SHARE_DIR	= $(DESTDIR)$(PREFIX)/share

APP_SHARE_DIR = $(INSTALL_SHARE_DIR)/$(APP_NAME)
DOC_SHARE_DIR = $(INSTALL_SHARE_DIR)/doc/$(APP_NAME)

COMMON_COMPILE_FLAGS = -Wall -pthread -O2
COMMON_LINK_FLAGS    = -pthread -s

# default build
CPPFLAGS  = $(COMMON_COMPILE_FLAGS) `wx-config --cxxflags --debug=no --unicode=yes`
LINKFLAGS = $(COMMON_LINK_FLAGS) `wx-config --libs std,aui --debug=no --unicode=yes`

all:
	@g++ $(CPPFLAGS) -c $(SRC_DIR)/*.cpp
	@g++ -o $(APP_NAME) *.o $(LINKFLAGS)

clean:
	@rm -f *.o *.depend *.layout
	@rm -rf ./bin/
	@rm -rf ./obj/
	@rm -f $(APP_NAME)

install:
	@mkdir -p $(INSTALL_BIN_DIR)
	@cp $(APP_NAME) $(INSTALL_BIN_DIR)

	@mkdir -p $(APP_SHARE_DIR)
	@cp -r ./resource $(APP_SHARE_DIR)

	@mkdir -p $(DOC_SHARE_DIR)
	@cp -r ./docs/* $(DOC_SHARE_DIR)

uninstall:
	@rm -f $(INSTALL_BIN_DIR)/$(APP_NAME)
	@rm -rf $(APP_SHARE_DIR)
	@rm -rf $(DOC_SHARE_DIR)
