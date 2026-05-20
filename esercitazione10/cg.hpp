#pragma once

#include <Eigen/Dense>
#include <iostream>

Eigen::VectorXd conjugate_gradient(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, Eigen::VectorXd x0, double tol = 1e-6, int max_iter = 10000)
{
	
	Eigen::VectorXd xk = x0;
	Eigen::VectorXd rk = b - A * xk; // r_0 = b - Ax_0
	Eigen::VectorXd pk = rk;         // p_0 = r_0
	
	int k = 0;
	
	while (rk.norm() > tol && k < max_iter)
	{
		
		Eigen::VectorXd Apk = A * pk;
		
		// alpha_k = (p_k^T r_k) / (p_k^T A p_k)
		double alpha_k = pk.dot(rk) / pk.dot(Apk);
		
		// x_{k+1} = x_k + alpha_k p_k
		xk = xk + alpha_k * pk;
		
		// r_{k+1} = b - Ax_{k+1}
		Eigen::VectorXd r_next = b - A * xk;
		
		// beta_k = (p_k^T A r_{k+1}) / (p_k^T A p_k)
		// A è simmetrica, p_k^T A r_{k+1} = (A p_k)^T r_{k+1}. 
		// Usiamo Apk già calcolato per risparmiare una moltiplicazione matrice-vettore
		double beta_k = Apk.dot(r_next) / pk.dot(Apk);
		
		// p_{k+1} = r_{k+1} - beta_k p_k
		pk = r_next - beta_k * pk;
		
		rk = r_next; // sggiorniamo il residuo
		k++;
	}
	
	std::cout << "Gradiente Coniugato converso in " << k << " iterazioni.\n";
	return xk;
}