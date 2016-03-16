# pg_hello_world - An example PostgreSQL extension written in C

This extension defines two functions:

* `HW_hello_world()`
* `HW_hello_world_shared_memory()`

Both return some kind of "Hello World" message. The difference is that the second
one takes its return value from shared memory.

# Compiling & Installing

```
make clean             # Delete all object files and other build artifacts

make all               # Compile the extension

make install           # Install the extension

make installcheck      # Check if the extension is installed by running the tests
                       # See:
                       #   ./sql/pg_hello_world_test.sql - The test file
                       #   ./expected/pg_hello_world_test.out - Expectations

make uninstall         # Uninstall the extension by deleting the files
```


