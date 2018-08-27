#!/bin/sh

fun=$1
prefix="$HOME/local/include"
folder="utils"

function hel() {
  echo "$0 all: for Install all functions."
  echo "$0 tc : for Install function time_cost."
  echo "$0 sp : for Install function string_split."
  echo "$0 mf : for Install function mmap_file."
  echo "$0 tn : for Install function type_name."
}

if [ "$#" -eq 0 ]; then
  echo "[Usage]: see $0 --help"
  hel
  exit
fi

function create_folder() {
  cd $prefix
  if [ ! -x "$folder" ]; then
    mkdir -p $folder
  fi
  cd -
}

function tc() {
  create_folder
  cp -f utils/time_cost.hpp "$prefix/$folder"
}

function sp() {
  create_folder
  cp -f utils/split.hpp "$prefix/$folder"
}

function mf() {
  create_folder
  cp -f utils/map_file.hpp "$prefix/$folder"
}

function tn() {
  create_folder
  cp -f utils/type_name.hpp "$prefix/$folder"
}

function all() {
  create_folder
  cp -f utils/*.hpp "$prefix/$folder"
}


if [ $fun = "--help" ]; then
  hel
elif [ $fun = "-h" ]; then
  hel
elif [ $fun = "all" ]; then
  all
elif [ $fun = "tc" ]; then
  tc
elif [ $fun = "sp" ]; then
  sp
elif [ $fun = "mf" ]; then
  mf
elif [ $fun = "tn" ]; then
  tn
else
  all
fi
