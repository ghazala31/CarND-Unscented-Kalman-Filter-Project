#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
	VectorXd rmse(4);
	rmse << 0,0,0,0;

	for (int i = 0; i < estimations.size(); i++) {
		VectorXd difference = estimations[i] - ground_truth[i];
		difference = difference.array() * difference.array();

		rmse += difference;
	}
	rmse = rmse / estimations.size();
	rmse = rmse.array().sqrt();

	return rmse;
}
