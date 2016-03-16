-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION pg_hello_world" to load this file. \quit

CREATE FUNCTION hello_world() RETURNS text
AS '$libdir/pg_hello_world', 'hello_world'
LANGUAGE C IMMUTABLE STRICT;

CREATE FUNCTION hello_world_shared_memory() RETURNS text
AS '$libdir/pg_hello_world', 'hello_world_shared_memory'
LANGUAGE C IMMUTABLE STRICT;
