/* ----------------------------------------------------------------------------
 * Copyright 2018, Ross Hartley <m.ross.hartley@gmail.com>
 * All Rights Reserved
 * See LICENSE for the license information
 * -------------------------------------------------------------------------- */

/**
 *  @file   NoiseParams.cpp
 *  @author Ross Hartley
 *  @brief  Source file for Invariant EKF noise parameter class
 *  @date   September 25, 2018
 **/

#include "NoiseParams.h"

namespace inekf {

using namespace std;

// ------------ NoiseParams -------------
// Default Constructor
NoiseParams::NoiseParams() {
    setGyroscopeNoise(0.01);
    setAccelerometerNoise(0.1);
    setGyroscopeBiasNoise(0.00001);
    setAccelerometerBiasNoise(0.0001);
    setLandmarkNoise(0.1);
    setContactNoise(0.1);
    setGpsNoise(0.1);
    setDepthNoise(0.1);
    setDvlNoise(0.1,10000);
}

void NoiseParams::setGyroscopeNoise(double std) { Qg_ = std*std*Eigen::Matrix3d::Identity(); }
void NoiseParams::setGyroscopeNoise(const Eigen::Vector3d& std) { Qg_ << std(0)*std(0),0,0, 0,std(1)*std(1),0, 0,0,std(2)*std(2); }
void NoiseParams::setGyroscopeNoise(const Eigen::Matrix3d& cov) { Qg_ = cov; }

void NoiseParams::setAccelerometerNoise(double std) { Qa_ = std*std*Eigen::Matrix3d::Identity(); }
void NoiseParams::setAccelerometerNoise(const Eigen::Vector3d& std) { Qa_ << std(0)*std(0),0,0, 0,std(1)*std(1),0, 0,0,std(2)*std(2); }
void NoiseParams::setAccelerometerNoise(const Eigen::Matrix3d& cov) { Qa_ = cov; } 

void NoiseParams::setGyroscopeBiasNoise(double std) { Qbg_ = std*std*Eigen::Matrix3d::Identity(); }
void NoiseParams::setGyroscopeBiasNoise(const Eigen::Vector3d& std) { Qbg_ << std(0)*std(0),0,0, 0,std(1)*std(1),0, 0,0,std(2)*std(2); }
void NoiseParams::setGyroscopeBiasNoise(const Eigen::Matrix3d& cov) { Qbg_ = cov; }

void NoiseParams::setAccelerometerBiasNoise(double std) { Qba_ = std*std*Eigen::Matrix3d::Identity(); }
void NoiseParams::setAccelerometerBiasNoise(const Eigen::Vector3d& std) { Qba_ << std(0)*std(0),0,0, 0,std(1)*std(1),0, 0,0,std(2)*std(2); }
void NoiseParams::setAccelerometerBiasNoise(const Eigen::Matrix3d& cov) { Qba_ = cov; }

void NoiseParams::setLandmarkNoise(double std) { Ql_ = std*std*Eigen::Matrix3d::Identity(); }
void NoiseParams::setLandmarkNoise(const Eigen::Vector3d& std) { Ql_ << std(0)*std(0),0,0, 0,std(1)*std(1),0, 0,0,std(2)*std(2); }
void NoiseParams::setLandmarkNoise(const Eigen::Matrix3d& cov) { Ql_ = cov; }

void NoiseParams::setContactNoise(double std) { Qc_ = std*std*Eigen::Matrix3d::Identity(); }
void NoiseParams::setContactNoise(const Eigen::Vector3d& std) { Qc_ << std(0)*std(0),0,0, 0,std(1)*std(1),0, 0,0,std(2)*std(2); }
void NoiseParams::setContactNoise(const Eigen::Matrix3d& cov) { Qc_ = cov; }

void NoiseParams::setGpsNoise(double std) { Qgps_ = std*std*Eigen::Matrix3d::Identity(); }
void NoiseParams::setGpsNoise(const Eigen::Vector3d& std) { Qgps_ << std(0)*std(0),0,0, 0,std(1)*std(1),0, 0,0,std(2)*std(2); }
void NoiseParams::setGpsNoise(const Eigen::Matrix3d& cov) { Qgps_ = cov; }

void NoiseParams::setDepthNoise(double std) { Qdepth_ << 1e15,0,0, 0,1e15,0, 0,0,std*std; }
void NoiseParams::setDepthNoise(const Eigen::Vector3d& std) { Qdepth_ << std(0)*std(0),0,0, 0,std(1)*std(1),0, 0,0,std(2)*std(2); }
void NoiseParams::setDepthNoise(const Eigen::Matrix3d& cov) { Qdepth_ = cov; }

void NoiseParams::setDvlNoise(double std, double std_z) { Qdvl_ << std*std,0,0, 0,std*std,0, 0,0,std_z*std_z; }
void NoiseParams::setDvlNoise(const Eigen::Vector3d& std) { Qdvl_ << std(0)*std(0),0,0, 0,std(1)*std(1),0, 0,0,std(2)*std(2); }
void NoiseParams::setDvlNoise(const Eigen::Matrix3d& cov) { Qdvl_ = cov; }

Eigen::Matrix3d NoiseParams::getGyroscopeCov() { return Qg_; }
Eigen::Matrix3d NoiseParams::getAccelerometerCov() { return Qa_; }
Eigen::Matrix3d NoiseParams::getGyroscopeBiasCov() { return Qbg_; }
Eigen::Matrix3d NoiseParams::getAccelerometerBiasCov() { return Qba_; }
Eigen::Matrix3d NoiseParams::getLandmarkCov() { return Ql_; }
Eigen::Matrix3d NoiseParams::getContactCov() { return Qc_; }
Eigen::Matrix3d NoiseParams::getGpsCov() { return Qgps_; }
Eigen::Matrix3d NoiseParams::getDepthCov() { return Qdepth_; }
Eigen::Matrix3d NoiseParams::getDvlCov() { return Qdvl_; }

std::ostream& operator<<(std::ostream& os, const NoiseParams& p) {
    os << "--------- Noise Params -------------" << endl;
    os << "Gyroscope Covariance:\n" << p.Qg_ << endl;
    os << "Accelerometer Covariance:\n" << p.Qa_ << endl;
    os << "Gyroscope Bias Covariance:\n" << p.Qbg_ << endl;
    os << "Accelerometer Bias Covariance:\n" << p.Qba_ << endl;
    os << "Landmark Covariance:\n" << p.Ql_ << endl;
    os << "Contact Covariance:\n" << p.Qc_ << endl;
    os << "GPS Covariance:\n" << p.Qgps_ << endl;
    os << "DEPTH Covariance:\n" << p.Qdepth_ << endl;
    os << "DVL Covariance:\n" << p.Qdvl_ << endl;
    os << "-----------------------------------" << endl;
    return os;
}

} // end inekf namespace
