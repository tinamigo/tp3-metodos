#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include "cml.h"

namespace py=pybind11;

// el primer argumento es el nombre...
PYBIND11_MODULE(metnum, m) {
    // py::class_<KNNClassifier>(m, "KNNClassifier")
    //     .def(py::init<unsigned int>())
    //     .def("fit", &KNNClassifier::fit)
    //     .def("predict", &KNNClassifier::predict);

    py::class_<CML>(m, "CML")
        .def(py::init<>())
        .def("fit", &CML::fit)
        .def("predict", &CML::predict)
        .def("coef", &CML::coefficient);
        
    // m.def(
    //     "power_iteration", &power_iteration,
    //     "Function that calculates eigenvector",
    //     py::arg("X"),
    //     py::arg("num_iter")=5000,
    //     py::arg("epsilon")=1e-16
    // );
    // m.def(
    //     "get_first_eigenvalues", &get_first_eigenvalues,
    //     "Function that calculates eigenvector",
    //     py::arg("X"),
    //     py::arg("num"),
    //     py::arg("num_iter")=5000,
    //     py::arg("epsilon")=1e-16
    // );

}
