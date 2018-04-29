#!/bin/bash

./dist_hash > Scripts/dist.dat
gnuplot -c "Scripts/dist_hash.gnu"
