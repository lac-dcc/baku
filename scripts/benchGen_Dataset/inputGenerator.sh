#!/bin/bash
OUTPUT_DIR="code/benchgen/src"
BENCHGEN_PATH=".gen/src/gen/benchGen"
GRAMMARS_PATH="code/benchgen/grammars/"

MIN_ITERATIONS=5
MAX_ITERATIONS=10

mkdir -p "$OUTPUT_DIR"

echo "Generating input files into: $OUTPUT_DIR"
echo

generate_input() {
    local run_num=$1
    local dataset_num=$2
    
    echo "Generating input for ${run_num}_${dataset_num}"
    ${BENCHGEN_PATH} "${run_num}" "${GRAMMARS_PATH}rules${dataset_num}.txt" "${GRAMMARS_PATH}seed${dataset_num}.txt" "${OUTPUT_DIR}/array${run_num}_${dataset_num}" array
    ${BENCHGEN_PATH} "${run_num}" "${GRAMMARS_PATH}rules${dataset_num}.txt" "${GRAMMARS_PATH}seed${dataset_num}.txt" "${OUTPUT_DIR}/sortedlist${run_num}_${dataset_num}" sortedlist
    echo
}

for run in $(seq ${MIN_ITERATIONS} ${MAX_ITERATIONS}); do
    for dataset in $(seq 1 20); do
        generate_input "${run}" "${dataset}"
    done
done

echo "All input files generated successfully in ${OUTPUT_DIR}/"
