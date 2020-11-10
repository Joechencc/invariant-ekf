/* ----------------------------------------------------------------------------
 * Copyright 2018, Ross Hartley
 * All Rights Reserved
 * See LICENSE for the license information
 * -------------------------------------------------------------------------- */

/**
 *  @file   NoiseParams.h
 *  @author Ross Hartley
 *  @brief  Header file for Invariant EKF noise parameter class
 *  @date   September 25, 2018
 **/
#ifndef NOISEPARAMS_H
#define NOISEPARAMS_H 
#include <Eigen/Dense>
#include <iostream>

namespace inekf {

class NoiseParams {

    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        NoiseParams();

        void setGyroscopeNoise(double std);
        void setGyroscopeNoise(const Eigen::Vector3d& std);
        void setGyroscopeNoise(const Eigen::Matrix3d& cov);

        void setAccelerometerNoise(double std);
        void setAccelerometerNoise(const Eigen::Vector3d& std);
        void setAccelerometerNoise(const Eigen::Matrix3d& cov);  

        void setGyroscopeBiasNoise(double std);
        void setGyroscopeBiasNoise(const Eigen::Vector3d& std);
        void setGyroscopeBiasNoise(const Eigen::Matrix3d& cov);

        void setAccelerometerBiasNoise(double std);
        void setAccelerometerBiasNoise(const Eigen::Vector3d& std);
        void setAccelerometerBiasNoise(const Eigen::Matrix3d& cov);  

        void setLandmarkNoise(double std);
        void setLandmarkNoise(const Eigen::Vector3d& std);
        void setLandmarkNoise(const Eigen::Matrix3d& cov);

        void setContactNoise(double std);
        void setContactNoise(const Eigen::Vector3d& std);
        void setContactNoise(const Eigen::Matrix3d& cov);

        void setGpsNoise(double std);
        void setGpsNoise(const Eigen::Vector3d& std);
        void setGpsNoise(const Eigen::Matrix3d& cov);

        void setDepthNoise(double std);
        void setDepthNoise(const Eigen::Vector3d& std);
        void setDepthNoise(const Eigen::Matrix3d& cov);

        void setDvlNoise(double std);
        void setDvlNoise(const Eigen::Vector3d& std);
        void setDvlNoise(const Eigen::Matrix3d& cov);

        Eigen::Matrix3d getGyroscopeCov();
        Eigen::Matrix3d getAccelerometerCov();
        Eigen::Matrix3d getGyroscopeBiasCov();
        Eigen::Matrix3d getAccelerometerBiasCov();
        Eigen::Matrix3d getLandmarkCov();
        Eigen::Matrix3d getContactCov();
        Eigen::Matrix3d getGpsCov();
        Eigen::Matrix3d getDepthCov();
        Eigen::Matrix3d getDvlCov();

        friend std::ostream& operator<<(std::ostream& os, const NoiseParams& p);  

    private:
        Eigen::Matrix3d Qg_;
        Eigen::Matrix3d Qa_;
        Eigen::Matrix3d Qbg_;
        Eigen::Matrix3d Qba_;
        Eigen::Matrix3d Ql_;
        Eigen::Matrix3d Qc_;
        Eigen::Matrix3d Qgps_;
        Eigen::Matrix3d Qdepth_;
        Eigen::Matrix3d Qdvl_;
};

} // end inekf namespace
#endif 
