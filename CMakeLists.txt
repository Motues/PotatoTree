cmake_minimum_required(VERSION 3.28)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/ThirdParties/CangoMake")
include("Cango")

project(PotatoTree
        VERSION 0.1
        DESCRIPTION "Build Your Tree"
        HOMEPAGE_URL "https://github.com/Motues/PotatoTree"
)

OverrideGlobalCXXStandard(23)
GuardGlobalBuildDirectory()
DefineBuildSystemMacros()
SuppressWindowsWarnings()

AddModulesInDirectory(
        DIRECTORY "Sources"
        NAMES
            "Test"
)