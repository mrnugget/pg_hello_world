EXTENSION = pg_hello_world

DATA = sql/pg_hello_world--0.0.1.sql pg_hello_world.control

MODULES = $(patsubst %.c,%,$(wildcard src/*.c))

TESTS        = $(wildcard test/sql/*.sql)
REGRESS      = $(patsubst test/sql/%.sql,%,$(TESTS))
REGRESS_OPTS = --inputdir=test

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
