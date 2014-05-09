#!/bin/bash

time=$(date "+%Y-%m-%d %H:%M:%S")

echo $time

cd ~/Github_practice
git add .
git commit -a -m "$time git-auto-saved"
