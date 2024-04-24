./replace tests/code.txt "code" " *** node ***"
./replace tests/cheese.txt "cheese" "*** nuts ***"
./replace tests/swearing.txt "****" "*** duck ***"

echo "--- Replace test code.txt ---"
diff -u tests/code.txt tests/code.txt.replaced | grep -E '^\+[^+]|^\-[^-]'
echo "--- Replace test cheese.txt ---"
diff -u tests/cheese.txt tests/cheese.txt.replaced | grep -E '^\+[^+]|^\-[^-]'
echo "--- Replace test swearing.txt ---"
diff -u tests/swearing.txt tests/swearing.txt.replaced | grep -E '^\+[^+]|^\-[^-]'
