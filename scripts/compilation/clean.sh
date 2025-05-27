#!/bin/bash

# Directory to clean .out files from
TARGET_DIR="$1"

# Check if the directory exists
if [ -d "$TARGET_DIR" ]; then
    # Find and remove all .out files in the directory
    find "$TARGET_DIR" -type f -name "*.out" -exec rm -f {} \;
    echo "All .out files have been removed from $TARGET_DIR."
else
    echo "Directory $TARGET_DIR does not exist."
fi