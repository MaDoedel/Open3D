#include "open3d/filters/BilateralFilterStrategy.h"


namespace open3d {
namespace filters {

    void BilateralFilterStrategy::apply(open3d::geometry::PointCloud in, open3d::geometry::PointCloud out) {
        std::cout << "Applying BilateralFilterStrategy" << std::endl;
    };
}
}