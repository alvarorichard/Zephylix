-- Define the target for your application
target("doubly_linked_list")
    -- Set the kind of target, in this case, a binary executable
    set_kind("binary")
    -- Add the source file(s). Assuming your code is in a single file named 'list.c'.
    add_files("main.c")
    -- Set the compiler to use. In this case, we're specifying 'clang'.
    set_toolchains("clang")
    -- Optimize for speed. The `-O3` flag is used for high level of optimization.
    add_cxflags("-O3")
    -- (Optional) If you want to include debug symbols for better debugging, uncomment the following line
    -- add_cxflags("-g")
