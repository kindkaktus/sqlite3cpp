sqlite3cpp
==========

SQLite3cpp is a C++ wrapper to SQLite3 C API.

The library was initially a clone from SQlite3pp from https://code.google.com/p/sqlite3pp/. The following adjustments were made to the original library:
- added a possibility to load sqlite extensions
- allowed for creation of the Db from SQL schema if it does not yet exist
- added support for foreign keys appeared in sqlite 3.6.19
- improved C++ interface (consistent usage of exceptions, non-throwing d'tors etc)
- dropped support for some rarely-used functionality like attach/detach/aggregate/function etc
