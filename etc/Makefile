#shell/makefile info
SHELL=/bin/bash
NAME=libuniclient

#declare compiler and linker
CC=gcc
LD=gcc
AR=ar

#helper vars to not use full path every time
#ALL PATHS STILL START FROM ROOT THIS IS JUST FOR EASE OF ACCESS
#as you can propably see they work recursively so changing one of them 
#is sufficient to change all sub-variables
ROOT=$(realpath $(dir $(lastword $(MAKEFILE_LIST))))
VAR=$(ROOT)/var
TMP=$(VAR)/tmp
LOCAL=$(ROOT)/local
SOURCEDIR=$(LOCAL)/src/c++
HEADDIR=$(LOCAL)/include
OBJDIR=$(TMP)/objects
LIB=$(LOCAL)/lib

#declare sources
SOURCES=*.cc
C_SOURCES=*.c
OBJ=*.o

#declare flags
CC_FLAGS=-c -Wall -fpic -O2 -std=c++17 -I $(HEADDIR)
LD_FLAGS=-shared -lstdc++ -shared-libgcc -lmariadb -lcurl -L /usr/local/lib/ -ltime.cc  -lcurl-php
AR_FLAGS=rvs

#system config
PROFILE_D=/etc/profile.d
INCLUDE_PATH=/usr/local/include/uniclient
SCRIPT_NAME=uniclient.sh
PHP=./php/

#php extension compile parameter config
PHP_NAME=uniclient.php
PHP_SOURCEDIR=./php/ext/
PHP_OBJDIR=$(TMP)/php_obj/
PHP_INI=uniclient.ini
PHP_C_FLAGS=-c -Wall -fpic -O2 -std=c++17 -I $(HEADDIR)
PHP_LD_FLAGS=-shared -lstdc++ -shared-libgcc -lphpcpp -L$(LIB) -l:libuniclient.a -l:libtime.cc.a  
PHP_CLI_INI_DIR=/etc/php/7.4/cli/conf.d
PHP_APACHE2_INI_DIR=/etc/php/7.4/apache2/conf.d
PHP_SYS_EXTENSION_DIR=$(shell php-config --extension-dir)

.PHONY:php

default:all

all:build php

build:
	@echo "##########################################################";
	@echo "Building UniClient library";
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
	$(LD) $(OBJDIR)/$(OBJ) $(LD_FLAGS) -o $(LIB)/$(NAME).so;
	#$(LD) $(OBJDIR)$(OBJ) $(LD_FLAGS) -o ./$(NAME);
	$(AR) $(AR_FLAGS) $(LIB)/$(NAME).a $(OBJDIR)/$(OBJ);
	@touch $(OBJDIR).lock;
	@echo "##########################################################";
	@echo "Building lib DONE!";
	@echo "Shared and static libs located under lib directory.";
	@echo "To install system-wide use 'make install' as root";
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

lib-install:
	@echo "##########################################################";
	@echo "Installing uniclient libraries";
	@echo "##########################################################";
	@if [ "$$USER" != "root" ]; then \
		echo "Please run install as root! Aborting." >&2; \
		@echo "##########################################################"; \
		exit 1; \
	fi
	cp -v $(LIB)* /usr/local/lib/;
	@if [ ! -d "$(INCLUDE_PATH)" ];then \
	mkdir -p $(INCLUDE_PATH); \
	fi
	cp -rv $(HEADDIR)* /usr/local/include/uniclient;
	@echo "#!/bin/bash" > $(PROFILE_D)/$(SCRIPT_NAME);
	@echo "export CPATH=\"/usr/local/include/uniclient:\$$CPATH\";" >> $(PROFILE_D)/$(SCRIPT_NAME);
	@echo "##########################################################";
	@echo "uniclient install successful!";
	@echo "PLEASE SOURCE THE PROFILE BEFORE USING!";
	@echo "##########################################################";

php-install:
	@echo "##########################################################";
	@echo "Installing the php extension for libauth.js";
	@echo "##########################################################";
	cp -v $(PHP_LIB)/* $(PHP_SYS_EXTENSION_DIR);
	echo "extension=$(PHP_NAME).so" > $(PHP_CLI_INI_DIR); 
	echo "extension=$(PHP_NAME).so" > $(PHP_APACHE2_INI_DIR); 
	@echo "##########################################################";
	@echo "DONE!";
	@echo "##########################################################";

#install:lib-install php-install
install:lib-install

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
