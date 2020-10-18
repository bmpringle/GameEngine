#!/usr/bin/env bash
case $1 in
  Rel)
    scons -j6 DBG=0 -c
    scons -j6 DBG=0 
    ;;
  Dbg)
    scons -j6 DBG=1 -c
    scons -j6 DBG=1
    ;;
  All)
    scons -j6 DBG=0 -c 
    scons -j6 DBG=1 -c 
    scons -j6 DBG=0 
    scons -j6 DBG=1 
    ;;
esac