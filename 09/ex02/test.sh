#!/bin/bash

# Color codes for better readability
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Test binary name
BINARY="./PmergeMe"

# Check if binary exists and is executable
if [ ! -x "$BINARY" ]; then
    echo -e "${RED}Error: $BINARY not found or not executable${NC}"
    echo "Compile the program first with 'make'"
    exit 1
fi

# Function to create random numbers
generate_random_numbers() {
    local count=$1
    local max=$2
    local numbers
    
    # Try shuf first (Linux)
    if command -v shuf &>/dev/null; then
        numbers=$(shuf -i 1-$max -n $count | tr "\n" " ")
    # Fall back to jot (MacOS)
    elif command -v jot &>/dev/null; then
        numbers=$(jot -r $count 1 $max | tr "\n" " ")
    else
        echo -e "${RED}Error: Neither shuf nor jot command found${NC}"
        return 1
    fi
    
    # Return the numbers
    echo "$numbers"
}

run_test() {
    local test_num=$1
    local description=$2
    local command=$3
    shift 3
    local args=("$@")
    
    echo -e "\n${YELLOW}Test $test_num: $description${NC}"
    echo -e "${BLUE}Command:${NC} $command ${args[*]}"
    echo -e "${CYAN}--- Program Output Begin ---${NC}"
    $command "${args[@]}"
    echo -e "${CYAN}--- Program Output End ---${NC}"
}

# Test case 1: Simple test with a few elements
run_test 1 "Small set of elements" $BINARY 3 5 9 7 4

# Test case 2: Single element
run_test 2 "Single element" $BINARY 42

# Test case 3: Two elements in wrong order
run_test 3 "Two elements in wrong order" $BINARY 9 1

# Test case 4: Already sorted
run_test 4 "Already sorted elements" $BINARY 1 2 3 4 5

# Test case 5: Duplicate elements
run_test 5 "Duplicate elements" $BINARY 3 1 2 1 5 2

# Test case 6: Invalid input (negative number)
run_test 6 "Invalid input - negative number" $BINARY 3 -5 9 7 4

# Test case 7: Invalid input (non-numeric)
run_test 7 "Invalid input - non-numeric" $BINARY 3 abc 9

# Test case 8: Empty input
run_test 8 "Empty input" $BINARY

# Test case 9: Medium set (100 elements)
numbers=$(generate_random_numbers 100 1000)
echo -e "\n${YELLOW}Test 9: Medium set (100 random elements)${NC}"
echo -e "${BLUE}Command:${NC} $BINARY [random numbers]"
echo -e "${CYAN}--- Program Output Begin ---${NC}"
$BINARY $numbers
echo -e "${CYAN}--- Program Output End ---${NC}"

# Test case 10: Large set (3000 elements) 
numbers=$(generate_random_numbers 3000 100000)
echo -e "\n${YELLOW}Test 10: Large set (3000 random elements)${NC}"
echo -e "${BLUE}Command:${NC} $BINARY [random numbers]"
echo -e "${CYAN}--- Program Output Begin ---${NC}"
$BINARY $numbers
echo -e "${CYAN}--- Program Output End ---${NC}"

# Test case 11: Very large set (10000 elements)
numbers=$(generate_random_numbers 10000 1000000)
echo -e "\n${YELLOW}Test 11: Very large set (10000 random elements)${NC}"
echo -e "${BLUE}Command:${NC} $BINARY [random numbers]"
echo -e "${CYAN}--- Program Output Begin ---${NC}"
$BINARY $numbers
echo -e "${CYAN}--- Program Output End ---${NC}"

echo -e "\n${GREEN}All tests completed${NC}"
