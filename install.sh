#!/bin/bash

#running dependancy installer
./install/S0-install-dep;

#sourcing profiles for now
source /etc/profile.d/libtime.cc.sh;
source /etc/profile.d/libauthjs.sh;

#running service installer
./install/S2-install-service;

#running npm
./install/S3-install-npm;

#creating libauthjs group and adding current user to it
./install/group;

#creating init script to initialize directories on startup
./install/init;
