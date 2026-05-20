#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>
#include "cg.hpp"

double condA(const Eigen::MatrixXd& A)
{
	Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
	Eigen::VectorXd singularValuesA = svd.singularValues();
	return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}

int main()
{
	// Provo con una matrice 10x10
	unsigned int n = 10;
	const double tol = 1.0e-12; // Tolleranza severa
	
	// Costruisco matrice A simmetrica definita positiva
	Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
	Eigen::MatrixXd A = B.transpose() * B;
	A += Eigen::MatrixXd::Identity(n, n);
	
	// Creo soluzione esatta e termine noto b
	Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
	Eigen::VectorXd b = A * x_ex;                   
	
	// Vettore di partenza x_0 (tutti 0)
	Eigen::VectorXd x0 = Eigen::VectorXd::Zero(n);
	
	std::cout << std::scientific << "Numero di condizionamento di A: " << condA(A) << std::endl;
	
	// Risolvo con l'algoritmo
	Eigen::VectorXd x_sol = conjugate_gradient(A, b, x0, tol, 10000);
	
	// Calcolo l'errore relativo rispetto alla soluzione esatta
	const auto err_rel = (x_ex.norm() == 0.0) ? (x_sol - x_ex).norm() :
	(x_sol - x_ex).norm() / x_ex.norm();
	
	std::cout << std::scientific << "Err relativo: " << err_rel << std::endl;
	
	std::cout << "Primi 3 elementi della soluzione calcolata: \n" 
	<< x_sol.head(3) << "\n...\n";
	
	return 0;
}