file(REMOVE_RECURSE
  "libalgo_lib.a"
  "libalgo_lib.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/algo_lib.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
