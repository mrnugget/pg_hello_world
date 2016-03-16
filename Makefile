# Name of our extension
EXTENSION = pg_hello_world

MODULES = pg_hello_world        # The C module we want to build
REGRESS = pg_hello_world_test   # The SQL test file we want to run

# The data that gets copied to the PostgreSQL folder when installing
DATA = pg_hello_world--0.0.1.sql pg_hello_world.control

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
