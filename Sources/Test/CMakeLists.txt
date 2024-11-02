project(Potato.Test)

AddCXXModule(
        NAME "Test"
        NAMESPACE "Potato"
        CXX_STANDARD 23
        HEADER_DIR Headers
        SOURCE_DIR Sources
        TESTER_DIR Testers
)