#include "open3d/filters/Filter.h"

namespace open3d {
namespace filters {

    void Filter::filter() {
        std::cout << "Applying Filter: ";
        filter_strategy_->apply(point_cloud_in_, point_cloud_out_);
    };

    void Filter::print() {
        std::cout << "Filtering point cloud" << std::endl;
    };
}
}