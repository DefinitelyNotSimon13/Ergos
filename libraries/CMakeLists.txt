add_library(Sqlite3 sqlite3.c)
target_link_libraries(MyDatabaseHandler PRIVATE Sqlite3)
