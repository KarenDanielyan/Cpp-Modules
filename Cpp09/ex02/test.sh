#!/bin/bash

args=$(ruby -e "puts (1..$1).to_a.shuffle.join(' ')")

./PmergeMe $args
