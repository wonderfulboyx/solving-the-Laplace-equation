#include <vector>
#include <Eigen/Core>
#include <Eigen/Sparse>


typedef Eigen::SparseMatrix<double> sp_mat;
typedef Eigen::Triplet<double> T;

void buildProblem(std::vector<T> &coffs, Eigen::VectorXd &b, int n);

int main(int argc, char **arfv)
{
    int n = 300;
    int m = n * n;

    std::vector<T> cofficients;
    Eigen::VectorXd b(m);
}
