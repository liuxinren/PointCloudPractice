#include "pointcloud.h"

PointCloud PointCloud::create(const std::string &filePath) {
    std::ifstream fin(filePath);
    if (!fin.is_open()) {
        std::cerr << "Error when opening file: " << filePath;
        return PointCloud();
    }

    double x, y, z, normal_x, normal_y, normal_z;
    char sep;
    int count = 0;
    PointCloud pointCloud;
    while (fin >> x >> sep >> y >> sep >> z >> sep >> normal_x >> sep >> normal_y >> sep >> normal_z) {
        Eigen::VectorXd tmp_xyz(3), tmp_normal(3);
        tmp_xyz << x, y, z;
        tmp_normal << normal_x, normal_y, normal_z;
        pointCloud.xyz.push_back(tmp_xyz);
        pointCloud.normal.push_back(tmp_normal);
        ++count;
    }
    std::cout << count << " points loaded\n";
    fin.close();

    return pointCloud;
}