#!bin/bash

ARG=`ruby -e "puts ($1 .. $2).to_a.shuffle.join(' ')"`
