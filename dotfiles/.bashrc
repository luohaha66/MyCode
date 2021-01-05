############################################################
# Simple but Cute and Helpful (TM) Bash Settings
#
# cat feedback >> "kirtika.ruchandani@gmail.com"
############################################################

#!/usr/bin/env bash
# ${HOME}/.bashrc: executed by bash(1) for non-login shells.
# If not running interactively, don't do anything
[ -z "$PS1" ] && return

# User Info
export USERNAME="Luo Wei Biao"
export NICKNAME="lwb"

# Distribute bashrc into smaller, more specific files
source ~/.shells/defaults
source ~/.shells/functions
source ~/.shells/exports
source ~/.shells/alias
source ~/.shells/prompt   # Fancy prompt with time and current working dir

# Local settings go last
if [ -f ~/.localrc ]; then
  source ~/.localrc
fi

# Welcome message
echo -ne "Hello, $NICKNAME! It's "; date '+%A, %B %-d %Y'
echo
