#!/bin/bash

# *************************************************
# config.sh
# -------------------
# This should be sourced in the profile of a sh,
# bash, ksh, or zsh shell.
# Last edited: September 18, 2011
# *************************************************

if [ "$INTROCS_CONFIG_SOURCED" != "true" ]; then

	# Standard libraries
	export CLASSPATH=$CLASSPATH:$HOME/introcs/stdlib.jar
	
	# Checkstyle and Findbugs
	export PATH=$PATH:$HOME/introcs/bin
	
	# Making sure these variables aren't doubly set
	export INTROCS_CONFIG_SOURCED=true
	
fi
