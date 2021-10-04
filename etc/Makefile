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
PHPFILE=$(LOCAL)/src/export.cc
HEADDIR=$(LOCAL)/include
OBJDIR=$(TMP)/objects
LIB=$(LOCAL)/lib
TESTDIR=$(TMP)/test
COMMANDDIR=$(LOCAL)/sources/commands
SHARE=$(LOCAL)/share


#microsun extension variables
MIC_SRC=$(SOURCEDIR)/microsun
MIC_HEAD=$(HEADDIR)/microsun
MIC_PHP=$(LOCAL)/src/microsun.cc

#declare sources
SOURCES=*.cc
C_SOURCES=*.c
OBJ=*.o

#declare flags
CC_FLAGS=-c -Wall -fpic -O2 -std=c++17 -I $(HEADDIR) -I$(MIC_HEAD)
LD_GENERAL=-shared -lstdc++ -shared-libgcc
LD_MICROSUN=$(LD_GENERAL) -lsqlite3 -L/usr/local/lib -l:libtime.cc.a
LD_UNICLIENT=$(LD_GENERAL) -lmariadb -ltime.cc 
AR_FLAGS=rvs

#system config
PROFILE_D=/etc/profile.d
INCLUDE_PATH=/usr/local/include/uniclient
SCRIPT_NAME=uniclient.sh
PHP=./php/

#php extension compile parameter config
PHP_NAME=uniclient.php
PHP_SOURCEDIR=$
PHP_OBJDIR=$(TMP)/php_obj/
PHP_INI=uniclient.ini
PHP_C_FLAGS=-c -Wall -fpic -O2 -std=c++17 -I $(HEADDIR) -I$(MIC_HEAD)
PHP_LD_FLAGS=-shared -lstdc++ -shared-libgcc -lphpcpp -L$(LIB) -l:libuniclient.a -l:libtime.cc.a -l:libmicrosun.a 
PHP_CLI_INI_DIR=/etc/php/7.4/cli/conf.d
PHP_APACHE2_INI_DIR=/etc/php/7.4/apache2/conf.d
PHP_SYS_EXTENSION_DIR=$(shell php-config --extension-dir)

.PHONY:php

default:all

all:uniclient microsun php

install:lib-install php-install
	service apache2 restart;


uniclient:
	@echo "##########################################################";
	@echo "Building UniClient library";
	@echo "##########################################################";
	@if [ -f $(OBJDIR).lock ]; then \
		echo "Removing objects from previous build"; \
		rm -f $(OBJDIR)/*; \
		rm -f $(OBJDIR).lock; \
	fi
	@for i in $(SOURCEDIR)/*/; \
	do \
		echo "making $$i"; \
		$(CC) "$$i"$(SOURCES) $(CC_FLAGS); \
	done
	@mv ./*.o $(OBJDIR);
	$(LD) $(OBJDIR)/$(OBJ) $(LD_UNICLIENT) -o $(LIB)/$(NAME).so;
	$(AR) $(AR_FLAGS) $(LIB)/$(NAME).a $(OBJDIR)/$(OBJ);
	@touch $(OBJDIR).lock;
	@echo "##########################################################";
	@echo "Building lib DONE!";
	@echo "Shared and static libs located under lib directory.";
	@echo "To install system-wide use 'make install' as root";
	@echo "##########################################################";

php:
	@echo "##########################################################";
	@echo "##########################################################";
	@echo "Building PHP extension for LibAuth.js server";
	@echo "##########################################################";
	@if [ -f $(OBJDIR)/.lock ]; then \
		echo "Removing objects from previous build"; \
		rm -f $(OBJDIR)/*; \
		rm -f $(OBJDIR)/.lock; \
	fi
	$(CC) $(PHPFILE) $(PHP_C_FLAGS);
	@mv ./*.o $(OBJDIR);
	$(LD) $(OBJDIR)/$(OBJ) -l:libauth.js.a -l:libmicrosun.a  $(PHP_LD_FLAGS) -o $(LIB)/$(PHP_NAME).so;
	@touch $(OBJDIR).lock;
	@echo "##########################################################";
	@echo "Done building LibAuth.js php extension!";
	@echo "##########################################################";
	@echo "Libs are located in the lib directory.";
	@echo "To install system-wide use 'make install' as root.";
	@echo "##########################################################";
	@echo "##########################################################";

lib-install:
	@echo "##########################################################";
	@echo "Installing uniclient libraries";
	@echo "##########################################################";
	@if [ "$$USER" != "root" ]; then \
		echo "Please run install as root! Aborting." >&2; \
		@echo "##########################################################"; \
		exit 1; \
	fi
	cp -v $(LIB)/libuniclient.so /usr/local/lib/;
	cp -v $(LIB)/libuniclient.a /usr/local/lib/;
	@if [ ! -d "$(INCLUDE_PATH)" ];then \
	mkdir -p $(INCLUDE_PATH); \
	fi
	cp -rv $(HEADDIR)/* $(INCLUDE_PATH);
	@echo "##########################################################";
	@echo "uniclient install successful!";
	@echo "##########################################################";

php-install:
	@echo "##########################################################";
	@echo "Installing the php extension for libauth.js";
	@echo "##########################################################";
	@cp -v $(LIB)/uniclient.php.so $(PHP_SYS_EXTENSION_DIR);
	echo "extension=$(PHP_NAME).so" > $(PHP_CLI_INI_DIR)/$(PHP_INI); 
	echo "extension=$(PHP_NAME).so" > $(PHP_APACHE2_INI_DIR)/$(PHP_INI); 
	@echo "##########################################################";
	@echo "DONE!";
	@echo "##########################################################";

microsun:
	@echo "##########################################################";
	@echo "copmiling microsun extension for uniclient";
	@echo "##########################################################"
	@rm -f $(OBJDIR)/*;
	$(CC) $(MIC_SRC)/$(SOURCES) $(CC_FLAGS);
	@if [ ! -d $(OBJDIR) ]; then \
		mkdir $(OBJDIR); \
	fi
	@if [ -f $(OBJDIR)/.lock ]; then \
		echo "Removing objects from previous build"; \
		rm -f $(OBJDIR)/*; \
		rm -f $(OBJDIR)/.lock; \
	fi
	@mv ./$(OBJ) $(OBJDIR);
	$(LD) $(OBJDIR)/$(OBJ) $(LD_MICROSUN) -o $(LIB)/libmicrosun.so;
	$(AR) $(AR_FLAGS) $(LIB)/libmicrosun.a $(OBJDIR)/$(OBJ);
	@echo "##########################################################";
	@echo "DONE!";
	@echo "##########################################################"

commands:
	for i in $(COMMANDDIR)/*/; \
	do \
		echo "making $$i"; \
		$(CC) "$$i" $(CC_FLAGS); \
	@mv ./$(OBJ) $(OBJDIR); \
	$(LD) $(OBJDIR)/$(OBJ) $(LD_MICROSUN) -o $(SHARE)/"$$i"; \
	@rm -f $(OBJDIR)/*;
	done

clean:
	#rm -fv $(OBJDIR)$(OBJ);
	#rm -fv $(PHP_OBJDIR)$(OBJ);
	#rm -fv $(STATIC)*;
	#rm -fv $(SHARED)*;
	#rm -fv $(PHP_LIB)*;
	#rm -fv $(PHP_SYS_EXTENSION_DIR)$(PHP_NAME).so;
	#rm -fv $(PHP_SYS_INI_DIR)$(PHP_INI);
	#rm -rf $(INCLUDE_PATH);
	#rm -fv $(PROFILE_D)$(SCRIPT_NAME);
