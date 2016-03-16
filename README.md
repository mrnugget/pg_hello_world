## pg_hello_world - An example PostgreSQL extension written in C

This extension defines two functions:

* `HW_hello_world()`
* `HW_hello_world_shared_memory()`

Both return some kind of "Hello World" message. The difference is that the second
one takes its return value from shared memory.

## Compiling & Installing

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

## Files

* `pg_hello_world.c` - Defines the functions in C
* `pg_hello_world--0.0.1.sql` - Uses `CREATE FUNCTION` to make the C functions accessible
* `pg_hello_world.control` - Meta-Data File
* `sql/pg_hello_world_test.sql` - Calls the functions as a test
* `expected/pg_hello_world_test.out` - The expected output when running the test file

## Resources

* http://big-elephants.com/2015-10/writing-postgres-extensions-part-i/
* http://big-elephants.com/2015-10/writing-postgres-extensions-part-ii/
* http://big-elephants.com/2015-10/writing-postgres-extensions-part-iii/
* http://big-elephants.com/2015-11/writing-postgres-extensions-part-iv/
* http://big-elephants.com/2015-11/writing-postgres-extensions-part-v/
* https://github.com/adjust/postgresql_extension_demo
* http://www.postgresql.org/docs/9.4/static/xfunc-c.html
