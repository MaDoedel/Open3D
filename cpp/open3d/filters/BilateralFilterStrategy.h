#pragma once

#include <iostream>
#include "open3d/filters/AbstractFilterStrategy.h"
#include "open3d/geometry/PointCloud.h"

namespace open3d {
namespace filters {

    class BilateralFilterStrategy : public AbstractFilterStrategy{
        private:
            float sigma_spatial_;
            float sigma_intensity_;
            std::function<float(float, float)> gaussian_;

        public:
            BilateralFilterStrategy(float sigma_spatial, float sigma_intensity): AbstractFilterStrategy(),
            sigma_spatial_(sigma_spatial), 
            sigma_intensity_(sigma_intensity),
            gaussian_([this](float intensity_dist, float sigma_r) { 
                return std::exp(-(intensity_dist * intensity_dist) / (2 * sigma_r * sigma_r));}){};

            void apply(open3d::geometry::PointCloud in, open3d::geometry::PointCloud out) override;
            
            inline void setGaussian(std::function<float(float, float)> gaussian) { gaussian_ = gaussian; };
            
    };
}
}