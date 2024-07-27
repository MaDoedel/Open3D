#include "open3d/filters/BilateralFilterStrategy.h"
#include "open3d/geometry/KDTreeFlann.h"


namespace open3d {
namespace filters {

    void BilateralFilterStrategy::apply(open3d::geometry::PointCloud in, open3d::geometry::PointCloud out) {
        std::cout << "BilateralFilterStrategy" << std::endl;

        float radius = 0.1;


        // Nice 3d Data Structure for 3D search
        open3d::geometry::KDTreeFlann kdtree(in);

        for (long unsigned int i = 0; i < in.points_.size(); i++) {
            float intensity_center = 0.2126f*in.colors_[i][0] + 0.7152f*in.colors_[i][1] + 0.0722f*in.colors_[i][2];
            std::vector<int> indices;
		    std::vector<double> distance; 
            // search for each point in the point cloud based on radius (as it is not an image, some n value would not make sense)
            kdtree.SearchRadius<Eigen::Vector3d>(in.points_[i], radius, indices, distance);

            for (int& index : indices) {
                // need intensity (luminance)
                float intensity_neighbor = 0.2126f*in.colors_[index][0] + 0.7152f*in.colors_[index][1] + 0.0722f*in.colors_[index][2];
                float intensity_dist = gaussian_(intensity_neighbor-intensity_center, sigma_intensity_);
                float spatial_dist = gaussian_((in.points_[index] - in.points_[i]).squaredNorm(), sigma_spatial_);
                std::cout << "Spatial Dist: " << spatial_dist << " Intensity Dist: " << intensity_dist << std::endl;
            }
        }
    };
}
}