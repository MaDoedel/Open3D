open3d_ispc_add_library(filters OBJECT)

target_sources(filters PRIVATE
    Filter.cpp
    BilateralFilterStrategy.cpp
)

open3d_show_and_abort_on_warning(filters)
open3d_set_global_properties(filters)
open3d_set_open3d_lib_properties(filters)
open3d_link_3rdparty_libraries(filters)
