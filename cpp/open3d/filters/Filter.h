#pragma once

#include <string>
#include <iostream>
#include <memory>
#include "open3d/geometry/PointCloud.h"
#include "open3d/filters/AbstractFilterStrategy.h"


// Startegy pattern
namespace open3d {
namespace filters {

    class Filter {

    private:
        open3d::geometry::PointCloud point_cloud_in_;
        open3d::geometry::PointCloud point_cloud_out_;
        std::unique_ptr<open3d::filters::AbstractFilterStrategy> filter_strategy_;

        
    public:
        Filter(open3d::geometry::PointCloud point_cloud_in, open3d::geometry::PointCloud point_cloud_out, std::unique_ptr<open3d::filters::AbstractFilterStrategy> filter_strategy) : 
            point_cloud_in_(point_cloud_in), 
            point_cloud_out_(point_cloud_out),
            filter_strategy_(std::move(filter_strategy)){};
        

        void filter();
        void print();

        inline void setFilterStrategy(std::unique_ptr<open3d::filters::AbstractFilterStrategy> filter_strategy) {
            filter_strategy_ = std::move(filter_strategy);
        }

        inline open3d::geometry::PointCloud getPointCloudIn() {
            return point_cloud_in_;
        }

        inline open3d::geometry::PointCloud getPointCloudOut() {
            return point_cloud_out_;
        }

        inline void setPointCloudIn(open3d::geometry::PointCloud point_cloud_in) {
            point_cloud_in_ = point_cloud_in;
        }

        inline void setPointCloudOut(open3d::geometry::PointCloud point_cloud_out) {
            point_cloud_out_ = point_cloud_out;
        }

    };
}
}
