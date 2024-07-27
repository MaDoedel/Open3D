#pragma once

#include <iostream>
#include "open3d/geometry/PointCloud.h"

// Startegy pattern
namespace open3d {
namespace filters {

class AbstractFilterStrategy {
    public:
        AbstractFilterStrategy() = default;
        virtual void apply(open3d::geometry::PointCloud in, open3d::geometry::PointCloud out) = 0;
    };

}
}