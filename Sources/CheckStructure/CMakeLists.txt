project(Potato.CheckStructure)

AddCXXModule(
        NAME "CheckStructure"
        NAMESPACE "Potato"
        CXX_STANDARD 23
        HEADER_DIR Headers
        SOURCE_DIR Sources
        TESTER_DIR Testers
)