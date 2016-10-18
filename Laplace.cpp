#include <vector>
#include <Eigen/Core>
#include <Eigen/Sparse>

#include <fstream>
#include <iostream>

typedef Eigen::SparseMatrix<double> SpMat;
typedef Eigen::Triplet<double> T;

void buildProblem(std::vector<T> &coffs, Eigen::VectorXd &b, int n);
void outputDat(const char *filename, const Eigen::VectorXd x, int n);

int main(int argc, char **argv)
{
    int n = 300;
    int m = n * n;

    std::vector<T> cofficients;
    Eigen::VectorXd b(m);

    buildProblem(cofficients, b, n);

    SpMat A(m, m);
    A.setFromTriplets(cofficients.begin(), cofficients.end());

    Eigen::SimplicialCholesky<SpMat> chol(A);
    Eigen::VectorXd x = chol.solve(b);

    outputDat(argv[1], x, n);
}

void setBoundary(std::vector<T> &coffs,int id, int i, int j,double w,
                        Eigen::VectorXd &b, int n)
{
    if(i == n){
        b(id) -= w * (double)j / (double)n;
    }
    else
    if(j == n){
        b(id) -= w * (double)i / (double)n;
    }
}

void insertCofficient(std::vector<T> &coffs,int id, int i, int j, double w,
                        Eigen::VectorXd &b, int n)
{
    int id1 = i + j * n;
    if (i == -1 || j == -1 || i == n || j == n)
    {
        setBoundary(coffs, id, i, j, w, b, n);
    }
    else
    {
        coffs.push_back(T(id, id1, w));
    }
}

void buildProblem(std::vector<T> &coffs, Eigen::VectorXd &b, int n)
{
    for (int i = 0; i < n;++i){
        for (int j = 0; j < n;++j){
            int id = i + j * n;
            insertCofficient(coffs, id, i - 1, j, -1.0, b, n);
            insertCofficient(coffs, id, i + 1, j, -1.0, b, n);
            insertCofficient(coffs, id, i, j + 1, -1.0, b, n);
            insertCofficient(coffs, id, i, j - 1, -1.0, b, n);
            insertCofficient(coffs, id, i, j, 4.0, b, n);
        }
    }
}

void outputDat(const char *filename, const Eigen::VectorXd x, int n)
{
    std::ofstream ofs(filename);
    ofs << "#X\tY\tZ"<<std::endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n;++j){
            int id = i + j * n;
            ofs << j << "\t" << i << "\t" << x(id) << std::endl;
        }
        ofs << std::endl;
    }
}