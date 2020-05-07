add_executable(cp2dir src/main.cpp)

# Add precompiled headers
target_precompile_headers(cp2dir PRIVATE src/pch.h)

target_compile_features(cp2dir PRIVATE cxx_std_17)

target_link_libraries(cp2dir PRIVATE
        cmd::cmd
        cp::cp)


