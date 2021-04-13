NAME=UniClient
CC=gcc
LD=gcc
AR=ar
SOURCEDIR=./sources/
SOURCES=*.cc
C_SOURCES=*.c
HEADDIR=./headers/
FUNCTION_DECLARATIONS=./headers/functions/
OBJDIR=./objects/
OBJ=*.o
SHARED=./lib/shared/
STATIC=./lib/static/
CC_FLAGS=-c -Wall -fpic -O2 -std=c++17 -I $(HEADDIR) -I $(FUNCTION_DECLARATIONS)
#LD_FLAGS=-shared -lstdc++ -shared-libgcc -lsqlite3 -lssl -lcrypto -L /usr/local/lib/ -ltime.cc 
LD_FLAGS=-lstdc++ -shared-libgcc -lmariadb -L /usr/local/lib/ -ltime.cc 
AR_FLAGS=rvs
SHELL=/bin/bash
PROFILE_D=/etc/profile.d/
INCLUDE_PATH=/usr/local/include/libauthjs
SCRIPT_NAME=libauthjs.sh
PHP=./php/

PHP_NAME=libauth.php
PHP_CC=gcc
PHP_LD=gcc
PHP_SOURCEDIR=./php/ext/
PHP_OBJDIR=./php/obj/
PHP_LIB=./php/lib/
PHP_INI=./php/libauth.js.ini
PHP_C_FLAGS=-c -Wall -fpic -O2 -std=c++17 -I $(HEADDIR) -I $(FUNCTION_DECLARATIONS)
PHP_LD_FLAGS=-shared -lstdc++ -shared-libgcc -lphpcpp -L$(STATIC) -l:libauth.js.a -l:libtime.cc.a  
#PHP_LD_FLAGS=-shared -lstdc++ -shared-libgcc -lphpcpp -l:libtime.cc.a  
PHP_SHELL=/bin/bash
PHP_SYS_INI_DIR=/etc/php/7.4/cli/conf.d
PHP_SYS_EXTENSION_DIR=$(shell php-config --extension-dir)

.PHONY:php

default:all

all:build php

build:
	@echo "##########################################################";
	@echo "Building libAuth.js library";
	@echo "##########################################################";
	@if [ -f $(OBJDIR).lock ]; then \
		echo "Removing objects from previous build"; \
		rm -f $(OBJDIR)*; \
		rm -f $(OBJDIR).lock; \
	fi
	@for i in $(SOURCEDIR)/*/; \
	do \
		echo "making $$i"; \
		$(CC) "$$i"$(SOURCES) $(CC_FLAGS); \
	done
	@mv ./*.o $(OBJDIR);
	#$(LD) $(OBJDIR)$(OBJ) $(LD_FLAGS) -o $(SHARED)$(NAME);
	$(LD) $(OBJDIR)$(OBJ) $(LD_FLAGS) -o ./$(NAME);
	#$(AR) $(AR_FLAGS) $(STATIC)$(NAME).a $(OBJDIR)$(OBJ);
	@touch $(OBJDIR).lock;
	@echo "##########################################################";
	@echo "Building lib DONE!";
	@echo "Shared and static libs located under lib directory.";
	@echo "To install system-wide use 'make install' as root";
	@echo "CAUTION:This does not install the full service! This is just the lib installer!";
	@echo "To install the full service please run the install bash script located in the root dir of the project";
	@echo "##########################################################";

#php:
	#@echo "##########################################################";
	#@echo "##########################################################";
	#@echo "Building PHP extension for LibAuth.js server";
	#@echo "##########################################################";
	#@if [ -f $(PHP_OBJDIR).lock ]; then \
		#echo "Removing objects from previous build"; \
		#rm -f $(PHP_OBJDIR)*; \
		#rm -f $(PHP_OBJDIR).lock; \
	#fi
	#$(PHP_CC) $(PHP_SOURCEDIR)$(SOURCES) $(PHP_C_FLAGS);
	#@mv ./*.o $(PHP_OBJDIR);
	#$(PHP_LD) $(PHP_OBJDIR)$(OBJ) ./lib/static/libauth.js.a  $(PHP_LD_FLAGS) -o $(PHP_LIB)$(PHP_NAME).so;
	#@touch $(PHP_OBJDIR).lock;
	#@echo "##########################################################";
	#@echo "Done building LibAuth.js php extension!";
	#@echo "##########################################################";
	#@echo "Libs are located in the lib directory.";
	#@echo "To install system-wide use 'make install' as root.";
	#@echo "##########################################################";
	#@echo "##########################################################";

#lib-install:
	#@echo "##########################################################";
	#@echo "Installing libauth.js libraries";
	#@echo "##########################################################";
	#@if [ "$$USER" != "root" ]; then \
		#echo "Please run install as root! Aborting." >&2; \
		#@echo "##########################################################"; \
		#exit 1; \
	#fi
	#cp -v $(SHARED)* /usr/local/lib/;
	#cp -v $(STATIC)* /usr/local/lib/;
	#@if [ ! -d "$(INCLUDE_PATH)" ];then \
	#mkdir -p $(INCLUDE_PATH); \
	#fi
	#cp -rv $(HEADDIR)* /usr/local/include/libauthjs;
	#@echo "#!/bin/bash" > $(PROFILE_D)$(SCRIPT_NAME);
	#@echo "export CPATH=\"/usr/local/include/libauthjs:/usr/local/include/libauthjs/functions:\$$CPATH\";" >> $(PROFILE_D)$(SCRIPT_NAME);
	#@echo "##########################################################";
	#@echo "libauth.js install successful!";
	#@echo "PLEASE SOURCE THE PROFILE BEFORE USING!";
	#@echo "##########################################################";

#php-install:
	#@echo "##########################################################";
	#@echo "Installing the php extension for libauth.js";
	#@echo "##########################################################";
	#cp -v $(PHP_LIB)/* $(PHP_SYS_EXTENSION_DIR);
	#cp -v $(PHP_INI) $(PHP_SYS_INI_DIR); 
	#@echo "##########################################################";
	#@echo "DONE!";
	#@echo "##########################################################";

#install:lib-install php-install
#install:lib-install

#clean:
	#rm -fv $(OBJDIR)$(OBJ);
	#rm -fv $(PHP_OBJDIR)$(OBJ);
	#rm -fv $(STATIC)*;
	#rm -fv $(SHARED)*;
	#rm -fv $(PHP_LIB)*;
	#rm -fv $(PHP_SYS_EXTENSION_DIR)$(PHP_NAME).so;
	#rm -fv $(PHP_SYS_INI_DIR)$(PHP_INI);
	#rm -rf $(INCLUDE_PATH);
	#rm -fv $(PROFILE_D)$(SCRIPT_NAME);
