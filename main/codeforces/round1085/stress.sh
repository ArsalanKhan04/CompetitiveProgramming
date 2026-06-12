g++ -O2 -o sol task5.cpp
g++ -O2 -o gen gen.cpp

for i in $(seq 1 10000); do
    ./gen $i > input.txt
    ./sol < input.txt > /dev/null 2>&1
    if [ $? -ne 0 ]; then
        echo "Assert fired on seed $i:"
        cat input.txt
        break
    fi
done
