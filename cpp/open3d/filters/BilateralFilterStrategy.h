#pragma once

#include <iostream>
#include "open3d/filters/AbstractFilterStrategy.h"
#include "open3d/geometry/PointCloud.h"

namespace open3d {
namespace filters {

    class BilateralFilterStrategy : public AbstractFilterStrategy{
        public:
            BilateralFilterStrategy() = default;
            void apply(open3d::geometry::PointCloud in, open3d::geometry::PointCloud out) override;
    };
}
}