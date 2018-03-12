#!/bin/sh

fun=$1
prefix="$HOME/local/include"
folder="utils"

if [ "$#" -eq 0 ]; then
    echo "[Usage]: see $0 --help"
    exit
fi

function create_folder() {
    cd $prefix
    if [ ! -x "$folder" ]; then
        mkdir $folder
    fi
    cd -
}

function tc() {
    create_folder
    cp -f time_cost.hpp "$prefix/$folder"
}

function all() {
    create_folder
    cp -f *.hpp "$prefix/$folder"
}


if [ $fun = "--help" ]; then
    echo "$0 all: for Install all functions."
    echo "$0 tc : for Install function time_cost."
elif [ $fun = "all" ]; then
    all
elif [ $fun = "tc" ]; then
    tc
fi
